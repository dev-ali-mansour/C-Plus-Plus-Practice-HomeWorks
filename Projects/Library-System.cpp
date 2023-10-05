#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;
const int MAX_BOOKS = 10;
const int MAX_USERS = 10;
const int ADD_BOOK = 1;
const int SEARCH_BOOKS = 2;
const int PRINT_WHO_BORROWED = 3;
const int PRINT_BY_ID = 4;
const int PRINT_BY_NAME = 5;
const int ADD_USER = 6;
const int BORROW_BOOK = 7;
const int RETURN_BOOK = 8;
const int PRINT_USERS = 9;
const int EXIT = 10;

struct book {
    int id;
    string name;
    int total_quantity;
    int borrowed_quantity;

    book() {
        id = -1;
        name = "";
        total_quantity = borrowed_quantity = 0;
    }

    void read() {
        cout << "Enter book info: id, name, and total total_quantity: ";
        cin >> id >> name >> total_quantity;
    }

    bool borrow(int user_iD) {
        if (total_quantity - borrowed_quantity == 0)
            return false;
        ++borrowed_quantity;
        return true;
    }

    void return_copy() {
        assert(borrowed_quantity > 0);
        --borrowed_quantity;
    }

    bool has_prefix(const string &prefix) {
        if (name.size() < prefix.size())
            return false;

        for (int i = 0; i < (int) prefix.size(); ++i) {
            if (prefix[i] != name[i])
                return false;
        }

        return true;
    }

    void print() {
        cout << "id = " << id << " name = " << name << " total_quantity = " << total_quantity
             << " borrowed_quantity = " << borrowed_quantity << endl;
    }
};

bool compare_book_by_name(const book &a, const book &b) {
    return a.name < b.name;
}

bool compare_book_by_id(const book &a, const book &b) {
    return a.id < b.id;
}

struct user {
    int id;
    string name;
    int borrowed_books_ids[MAX_BOOKS];
    int len;

    user() {
        id = 0;
        name = "";
        len = 0;
    }

    void read() {
        cout << "Enter user name & nationl id: ";
        cin >> name >> id;
    }

    void borrow_book(int book_id) {
        borrowed_books_ids[len++] = book_id;
    }

    void return_copy(int book_id) {
        bool removed = false;
        for (int i = 0; i < len; ++i) {
            if (borrowed_books_ids[i] == book_id) {
                // Let's shift the array to the right to remove this book
                for (int j = i; j < len; ++j)
                    borrowed_books_ids[j] = borrowed_books_ids[j + 1];
                removed = true;
                --len;
                break;
            }
        }

        if (!removed)
            cout << "User " << name << " never borrowed book id " << book_id << endl;
    }

    bool is_borrowed(int book_id) {
        for (int i = 0; i < len; ++i) {
            if (borrowed_books_ids[i] == book_id)
                return true;
        }
        return false;
    }

    void print() {
        // Sort what he borrowed
        sort(borrowed_books_ids, borrowed_books_ids + len);

        cout << " User " << name << " id " << id << " borrowed books ids : ";
        for (int i = 0; i < len; ++i) {
            cout << borrowed_books_ids[i] << " ";
        }
        cout << endl;
    }

};

struct library_system {
    int total_books;
    book books[MAX_BOOKS];
    int total_users;
    user users[MAX_USERS];

    library_system() {
        total_books = 0, total_users = 0;
    }

    void run() {
        cout << "\nLibrary Menu:\n";
        cout << ADD_BOOK << ") add_book\n";
        cout << SEARCH_BOOKS << ") search_books_by_prefix\n";
        cout << PRINT_WHO_BORROWED << ") print_who_borrowed_book_by_name\n";
        cout << PRINT_BY_ID << ") print_library_by_id\n";
        cout << PRINT_BY_NAME << ") print_library_by_name\n";
        cout << ADD_USER << ") add_user\n";
        cout << BORROW_BOOK << ") user_borrow_book\n";
        cout << RETURN_BOOK << ") user_return_book\n";
        cout << PRINT_USERS << ") print_users\n";
        cout << EXIT << ") Exit\n";

        while (true) {
            int choice = menu();
            if (choice == ADD_BOOK)
                add_book();
            else if (choice == SEARCH_BOOKS)
                search_books_by_prefix();
            else if (choice == PRINT_WHO_BORROWED)
                print_who_borrowed_book_by_name();
            else if (choice == PRINT_BY_ID)
                print_library_by_id();
            else if (choice == PRINT_BY_NAME)
                print_library_by_name();
            else if (choice == ADD_USER)
                add_user();
            else if (choice == BORROW_BOOK)
                user_borrow_book();
            else if (choice == RETURN_BOOK)
                user_return_book();
            else if (choice == PRINT_USERS)
                print_users();
            else if (choice == EXIT)
                break;
        }
    }

    int menu() {
        int choice = -1;
        cout << "Enter your menu choice [1-10]: ";
        cin >> choice;

        while (choice > EXIT || choice < ADD_BOOK) {
            cout << "Invalid choice! Try again: ";
            cin >> choice;
        }
        return choice;
    }

    void add_book() {
        books[total_books++].read();
    }

    void search_books_by_prefix() {
        string prefix;
        cout << "Enter book name prefix: ";
        cin >> prefix;

        int cnt = 0;
        for (int i = 0; i < MAX_BOOKS; ++i) {
            if (books[i].has_prefix(prefix)) {
                cout << books[i].name << endl;
                ++cnt;
            }
        }

        if (!cnt)
            cout << "No books with such prefix\n";
    }

    void print_who_borrowed_book_by_name() {
        string book_name;
        cout << "Enter book name: ";
        cin >> book_name;

        int book_idx = find_book_idx_by_name(book_name);
        if (book_idx == -1) {
            cout << "Invalid book name.\n";
            return;
        }

        int book_id = books[book_idx].id;
        for (int i = 0; i < MAX_USERS; ++i) {
            if (users[i].is_borrowed(book_id)) {
                cout << users[i].name << endl;
            }
        }
    }

    void print_library_by_id() {
        sort(books, books + total_books, compare_book_by_id);
        for (int i = 0; i < total_books; ++i) {
            books[i].print();
        }
    }

    void print_library_by_name() {
        sort(books, books + total_books, compare_book_by_name);
        for (int i = 0; i < total_books; ++i) {
            books[i].print();
        }
    }

    void add_user() {
        users[total_users++].read();
    }

    int find_user_idx_by_name(const string &user_name) {
        for (int i = 0; i < MAX_USERS; ++i) {
            if (users[i].name == user_name)
                return i;
        }
        return -1;
    }

    int find_book_idx_by_name(const string &book_name) {
        for (int i = 0; i < MAX_BOOKS; ++i) {
            if (books[i].name == book_name)
                return i;
        }
        return -1;
    }

    bool read_user_name_and_book_name(int &user_idx, int &book_idx, int trials = 3) {
        string user_name, book_name;
        while (trials--) {
            cout << "Enter user name and book name: ";
            cin >> user_name >> book_name;
            user_idx = find_user_idx_by_name(user_name);
            if (user_idx == -1) {
                cout << "Invalid user name! Try again\n";
                continue;
            }
            book_idx = find_book_idx_by_name(book_name);
            if (book_idx == -1) {
                cout << "Invalid book name! Try again\n";
                continue;
            }
            return true;
        }
        cout << "You did several trials! Try later.\n";
        return false;
    }

    void user_borrow_book() {
        int user_idx, book_idx;
        if (!read_user_name_and_book_name(user_idx, book_idx))
            return;

        int user_id = users[user_idx].id;
        int book_id = books[book_idx].id;

        if (!books[book_idx].borrow(user_id))
            cout << "No more copies available right now!\n";
        else
            users[user_idx].borrow_book(book_id);
    }

    void user_return_book() {
        int user_idx, book_idx;
        if (!read_user_name_and_book_name(user_idx, book_idx))
            return;

        int book_id = books[book_idx].id;
        books[book_idx].return_copy();
        users[user_idx].return_copy(book_id);
    }

    void print_users() {
        for (int i = 0; i < total_users; ++i) {
            users[i].print();
        }
    }
};

int main() {
    library_system system;
    system.run();

    return 0;
}