#include <iostream>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;

int readInt(int low, int high) {
    cout << "\nEnter number in range " << low << " - " << high << ":";
    int value;
    cin >> value;
    if (low <= value && value <= high)
        return value;
    cout << "Error: Invalid number... Try again\n";
    return readInt(low, high);
}

int showReadMenu(const vector<string> &choices) {
    cout << "\nMenu:\n";
    for (int ch = 0; ch < (int) choices.size(); ++ch) {
        cout << "\t" << ch + 1 << ": " << choices[ch] << endl;
    }
    return readInt(1, (int) choices.size());
}

string
getCurrentTimeDate() {// src: https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

class Book {
private:
    string isbn;
    string title;
    string author;
    vector<string> pages;

public:
    void read() {
        string str;

        cout << "Enter ISBN: ";
        cin >> str;
        setIsbn(str);

        cout << "Enter Title: ";
        cin >> str;
        setTitle(str);

        cout << "Enter Author Name: ";
        cin >> str;
        setAuthor(str);
        cout << "Enter How many pages: ";
        int pages_count;
        cin >> pages_count;
        for (int page = 0; page < pages_count; ++page) {
            cout << "Enter page # " << page + 1 << ": ";
            cin >> str;
            pages.push_back(str);
        }
    }

    const string &getIsbn() const {
        return isbn;
    }

    void setIsbn(const string &isbn) {
        Book::isbn = isbn;
    }

    const string &getTitle() const {
        return title;
    }

    void setTitle(const string &title) {
        Book::title = title;
    }

    const string &getAuthor() const {
        return author;
    }

    void setAuthor(const string &author) {
        Book::author = author;
    }

    const vector<string> &getPages() const {
        return pages;
    }

    void setPages(const vector<string> &pages) {
        Book::pages = pages;
    }

    string toString() {
        return title;
    }
};

class BookReadingSession {
private:
    // Using a pointer is a bad design choice here: what if the original book removed now by admin? We access garbage!
    // A more proper way: use book isbn, and later use book manager to find the book
    Book *book;    // Note, we did not create this pointer. Someone else should destroy
    int current_page;
    string last_access_date;

public:

    BookReadingSession() : BookReadingSession(nullptr) {
    }

    BookReadingSession(Book *book) :
            book(book), current_page(0), last_access_date(getCurrentTimeDate()) {
    }

    string toString() {
        ostringstream oss;
        oss << getBook()->getTitle() << " Page: " << pageIdxStr() << " - " << getLastAccessDate();
        return oss.str();
    }

    string getCurrentPageContent() {
        return book->getPages()[current_page];
    }

    const Book *getBook() {
        return book;    // No set
    }

    const string &getLastAccessDate() const {
        return last_access_date;
    }

    void resetLastAccessDate() {    // More convenient
        last_access_date = getCurrentTimeDate();
    }

    int geCurrentPage() const {
        return current_page;
    }

    string pageIdxStr() {
        ostringstream oss;
        oss << geCurrentPage() + 1 << "/" << book->getPages().size();
        return oss.str();
    }

    void nextPage() {
        if (current_page < (int) book->getPages().size() - 1)
            current_page++;
    }

    void previousPage() {
        if (current_page > 0)
            current_page--;
    }
};

class User {
private:
    string user_name;
    string password;
    string name;
    string email;
    bool is_library_admin;
    vector<BookReadingSession *> reading_sessions;

public:
    // If you have pointers internally: start with canceling copy constructor, so that you discover any bugs due to misuse
    // Provide it based on logic & needs
    User(const User &) = delete;

    void operator=(const User &) = delete;

    User() {
        is_library_admin = false;
    }

    ~User() {
        cout << "Destructor User\n";
        for (auto &session: reading_sessions)
            delete session;

        reading_sessions.clear();
    }

    string toString() const {
        ostringstream oss;
        oss << "Name: " << user_name;
        if (isLibraryAdmin())
            oss << " | Admin";
        oss << endl;
        oss << "Email: " << email << endl;
        oss << "User name: " << user_name << endl;
        return oss.str();
    }

    void read(const string &user_name) {
        setUserName(user_name);

        string str;

        cout << "Enter password (no spaces): ";
        cin >> str;
        setPassword(str);

        cout << "Enter name (no spaces): ";
        cin >> str;
        setName(str);

        cout << "Enter email (no spaces): ";
        cin >> str;
        setEmail(str);
    }

    const string &getUserName() const {
        return user_name;
    }

    void setUserName(const string &userName) {
        user_name = userName;
    }

    const string &getPassword() const {
        return password;
    }

    void setPassword(const string &password) {
        User::password = password;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        User::name = name;
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &email) {
        User::email = email;
    }

    bool isLibraryAdmin() const {
        return is_library_admin;
    }

    void setIsLibraryAdmin(bool isLibraryAdmin) {
        is_library_admin = isLibraryAdmin;
    }

    const vector<BookReadingSession *> &getReadingSessions() const {
        // Note: Although the return is const vector, but the pointer is not const, so someone can cause problems using setters on pointer
        return reading_sessions;    // No set
    }

    BookReadingSession *addReadingSession(Book *book) {
        // We create pointer & later delete it
        BookReadingSession *session = new BookReadingSession(book);
        reading_sessions.push_back(session);
        return session;
    }

};

class UsersManager {
private:
    User *current_user{nullptr};
    map<string, User *> username_userobject_map;

    void freeLoadedData() {
        for (auto pair: username_userobject_map) {
            delete pair.second;

            username_userobject_map.clear();
            current_user = nullptr;
        }
    }

public:
    UsersManager() {
    }

    ~UsersManager() {
        cout << "Destructor UsersManager\n";
        freeLoadedData();
    }

    // No sense for such a class (manager of objects) to be copyable!
    // This is a C++ 11 feature that prevents Copy constructor and Assignment Operator (=)from being called. It delete then from the class
    // https://ariya.io/2015/01/c-class-and-preventing-object-copy#:~:text=There%20are%20three%20ways%20to,have%20its%20instance%20copied%20around.
    UsersManager(const UsersManager &) = delete;

    void operator=(const UsersManager &) = delete;

    void loadDatabase() {
        if (username_userobject_map.size() > 0)
            return;     // Let's assume 1 run for the system only

        cout << "UsersManager: loadDatabase\n";
        freeLoadedData();
        // Some dummy data for simplicity
        User *user1 = new User();
        user1->setUserName("ali");
        user1->setPassword("111");
        user1->setEmail("dev.ali.mansour@gmail.com");
        user1->setName("Ali Mansour Mohamed");
        user1->setIsLibraryAdmin(true);
        username_userobject_map[user1->getUserName()] = user1;

        User *user2 = new User();
        user2->setUserName("asmaa");
        user2->setPassword("222");
        user2->setEmail("asmaa@gmail.com");
        user2->setName("Asmaa Saad Ibrahim");
        username_userobject_map[user2->getUserName()] = user2;
    }

    void accessSystem() {
        int choice = showReadMenu({"Login", "Sign Up"});
        if (choice == 1) doLogin();
        else doSignUp();
    }

    void doLogin() {
        loadDatabase();

        while (true) {
            string username, pass;
            cout << "Enter username (no spaces): ";
            cin >> username;
            cout << "Enter password (no spaces): ";
            cin >> pass;

            if (!username_userobject_map.count(username)) {
                cout << "\nInvalid username or password! Try again\n\n";
                continue;
            }

            User *user_exist = username_userobject_map.find(username)->second;

            if (pass != user_exist->getPassword()) {
                cout << "\nInvalid username or password! Try again\n\n";
                continue;
            }
            current_user = user_exist;
            break;
        }
    }

    void doSignUp() {
        string username;
        while (true) {
            cout << "Enter username (no spaces): ";
            cin >> username;

            if (username_userobject_map.count(username))
                cout << "Already used! Try again\n";
            else break;
        }
        current_user = new User();
        current_user->read(username);
        string t = current_user->getUserName();
        username_userobject_map[current_user->getUserName()] = current_user;
    }

    BookReadingSession *addReadingSession(Book *book) {
        return current_user->addReadingSession(book);
    }

    const User *getCurrentUser() const {
        return current_user;
    }
};

class BooksManager {
private:
    map<string, Book *> isbn_to_book_map;

    void freeLoadedData() {
        for (auto pair: isbn_to_book_map) {
            delete pair.second;
        }
        isbn_to_book_map.clear();
    }

public:
    BooksManager() {
    }

    void loadDatabase() {
        cout << "BookManager: loadDatabase\n";
        freeLoadedData();

        Book *book1 = new Book();
        book1->setIsbn("00001");
        book1->setAuthor("Mostufa");
        book1->setTitle("C++ How to program");
        vector<string> pages1 = {"A C++", "B C++", "C C++", "D C++", "E C++"};
        book1->setPages(pages1);
        addBook(book1);

        Book *book2 = new Book();
        book2->setIsbn("00002");
        book2->setAuthor("Morad");
        book2->setTitle("Intro to algo");
        vector<string> pages2 = {"A Algo", "B Algo", "C Algo", "D Algo", "E "};
        book2->setPages(pages2);
        addBook(book2);

        Book *book3 = new Book();
        book3->setIsbn("00003");
        book3->setAuthor("Morad");
        book3->setTitle("Data Structures in C++");
        vector<string> pages3 = {"A Data", "B Data", "C Data", "D Data", "E Data"};
        book3->setPages(pages3);
        addBook(book3);
    }

    BooksManager(const BooksManager &) = delete;

    void operator=(const BooksManager &) = delete;

    ~BooksManager() {
        cout << "BookManager Destructor\n";
        freeLoadedData();
    }

    // CRUD Operations
    void addBook(Book *book) {
        isbn_to_book_map[book->getIsbn()] = book;
    }

    void updateBook(const string &isbn, Book *book) {
    }

    void deleteBook(const string &isbn) {
    }

    Book *getBook(const string &isbn) {
        return nullptr;
    }

    const map<string, Book *> &getIsbnToBookMap() const {
        return isbn_to_book_map;
    }

    void setIsbnToBookMap(const map<string, Book *> &isbnToBookMap) {
        isbn_to_book_map = isbnToBookMap;
    }
};

class UserView {
private:
    UsersManager &usersManager;
    BooksManager &booksManager;

public:
    UserView(UsersManager &usersManager, BooksManager &booksManager) :
            usersManager(usersManager), booksManager(booksManager) {}

    void display() {
        const User *user = usersManager.getCurrentUser();
        cout << "\n\nHello " << user->getName() << " | User View\n";

        vector<string> menu;
        menu.push_back("View Profile");
        menu.push_back("List & Select from My Reading History");
        menu.push_back("List & Select from Available Books");
        menu.push_back("Logout");

        while (true) {
            int choice = showReadMenu(menu);
            if (choice == 1) viewProfile();
            else if (choice == 2) listReadingHistory();
            else if (choice == 3)listAvailableBooks();
            else break;
        }
    }

    void viewProfile() {
        const User *user = usersManager.getCurrentUser();
        cout << endl << user->toString() << endl;
    }

    void displaySession(BookReadingSession *session) {
        vector<string> menu;
        menu.push_back("Next Page");
        menu.push_back("Previous Page");
        menu.push_back("Stop Reading");

        while (true) {
            cout << "Current Page: " << session->pageIdxStr() << "\n";
            cout << session->getCurrentPageContent() << "\n";

            int choice = showReadMenu(menu);
            if (choice == 1)
                session->nextPage();
            else if (choice == 2)
                session->previousPage();
            else
                break;
        }
        session->resetLastAccessDate();
    }

    void listReadingHistory() {
        int idx = 0;
        const auto &sessions = usersManager.getCurrentUser()->getReadingSessions();
        for (auto &session: sessions) {
            cout << ++idx << ": " << session->toString() << "\n";
        }

        if (idx == 0)
            cout << "\nNo history. List books and start having fun\n";
        else {
            cout << "\nWhich session to open?: ";
            int choice = readInt(1, idx);
            displaySession(sessions[choice - 1]);
        }
    }

    void listAvailableBooks() {
        const map<string, Book *> &mp = booksManager.getIsbnToBookMap();

        cout << "\nOur current book collection:\n";
        int idx = 0;
        for (const auto &pair: mp) {
            // As we call ToString: we don't need to worry about book data members future changes
            cout << "\t" << ++idx << " " << pair.second->toString() << "\n";
        }

        cout << "\nWhich book to read?: ";
        int choice = readInt(1, idx);    // For simplicity, assume a new book is selected

        idx = 0;
        for (const auto &pair: mp) {
            if (++idx == choice) {
                BookReadingSession *session = usersManager.addReadingSession(pair.second);
                displaySession(session);
                break;
            }
        }

    }
};

class AdminView {
private:
    UsersManager &usersManager;
    BooksManager &booksManager;

public:
    AdminView(UsersManager &usersManager, BooksManager &booksManager) :
            usersManager(usersManager), booksManager(booksManager) {}

    void display() {
        const User *user = usersManager.getCurrentUser();

        cout << endl << endl << user->getName() << " | Admin View\n";
        vector<string> menu;
        menu.push_back("View Profile");
        menu.push_back("Add Book");
        menu.push_back("Logout");

        while (true) {
            int choice = showReadMenu(menu);
            if (choice == 1)
                viewProfile();
            else if (choice == 2)
                addBook();
            else
                break;
        }
    }

    void viewProfile() {
        const User *user = usersManager.getCurrentUser();
        cout << endl << user->toString() << endl;
    }

    void addBook() {
        Book *book = new Book();
        book->read();
        booksManager.addBook(book);
    }
};

class OnlineReaderSystem {
private:
    UsersManager *usersManager;
    BooksManager *booksManager;

    void loadDatabase() {
        usersManager->loadDatabase();
        booksManager->loadDatabase();
    }

public:
    OnlineReaderSystem() : booksManager(new BooksManager()), usersManager(new UsersManager()) {
    }

    ~OnlineReaderSystem() {
        cout << "Destructor: OnlineReaderSystem\n";

        if (usersManager != nullptr) {
            delete usersManager;
            usersManager = nullptr;
        }
        if (booksManager != nullptr) {
            delete booksManager;
            booksManager = nullptr;
        }
    }

    void run() {    // only public one
        loadDatabase();

        while (true) {
            usersManager->accessSystem();   // Login/SignUp

            // Let's make for every user, its own viewer class: Remember: Single responsibility principle
            if (usersManager->getCurrentUser()->isLibraryAdmin()) {
                AdminView view(*usersManager, *booksManager);
                view.display();
            } else {
                UserView view(*usersManager, *booksManager);
                view.display();
            }
        }
    }
};

int main() {
    OnlineReaderSystem site;

    site.run();

    return 0;
}