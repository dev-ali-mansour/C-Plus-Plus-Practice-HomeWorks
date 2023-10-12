#include <iostream>
#include <algorithm>
#include <cassert>
#include <set>
#include <vector>

using namespace std;
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

    bool borrow() {
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
    set<int> borrowed_books_ids;

    user() {
        id = 0;
        name = "";
    }

    void read() {
        cout << "Enter user name & nationl id: ";
        cin >> name >> id;
    }

    void borrow_book(int book_id) {
        borrowed_books_ids.insert(book_id);
    }

    void return_copy(int book_id) {
        auto it = borrowed_books_ids.find(book_id);

        if (it != borrowed_books_ids.end())
            borrowed_books_ids.erase(it);
        else
            cout << "User " << name << " never borrowed book id " << book_id << endl;
    }

    bool is_borrowed(int book_id) {
        auto it = borrowed_books_ids.find(book_id);
        return it != borrowed_books_ids.end();
    }

    void print() {
        cout << " User " << name << " id " << id << " borrowed books ids : ";
        for (int book_id: borrowed_books_ids) {
            cout << book_id << " ";
        }
        cout << endl;
    }

};

struct library_system {
    vector<book> books;
    vector<user> users;

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
        book b;
        b.read();
        books.push_back(b);
    }

    void search_books_by_prefix() {
        string prefix;
        cout << "Enter book name prefix: ";
        cin >> prefix;

        int cnt = 0;
        for (auto & book : books) {
            if (book.has_prefix(prefix)) {
                cout << book.name << endl;
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
        for (auto & user : users) {
            if (user.is_borrowed(book_id)) {
                cout << user.name << endl;
            }
        }
    }

    void print_library_by_id() {
        sort(books.begin(), books.end(), compare_book_by_id);
        cout << endl;
        for (book &b: books) {
            b.print();
        }
    }

    void print_library_by_name() {
        sort(books.begin(), books.end(), compare_book_by_name);
        cout << endl;
        for (book &b: books) {
            b.print();
        }
    }

    void add_user() {
        user u;
        u.read();
        users.push_back(u);
    }

    int find_user_idx_by_name(const string &user_name) {
        for (int i = 0; i < (int) books.size(); ++i) {
            if (users[i].name == user_name)
                return i;
        }
        return -1;
    }

    int find_book_idx_by_name(const string &book_name) {
        for (int i = 0; i < (int) books.size(); ++i) {
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

        int book_id = books[book_idx].id;

        if (!books[book_idx].borrow())
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
        cout << endl;
        for (user &u: users) {
            u.print();
        }
    }
};

int main() {
    library_system system;
    system.run();

    return 0;
}