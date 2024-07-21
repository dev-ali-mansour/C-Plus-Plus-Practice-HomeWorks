#include <iostream>
#include <memory>

using namespace std;

struct LegacyDatabase {
    void release() {}

    ~LegacyDatabase() {}
};

void deleter(LegacyDatabase *db) {
    cout << "Special delete 1\n";
    db->release();
    delete db;
}

void oldWay() {
    // Sadly badly designed legacy code
    auto *db = new LegacyDatabase();
    db->release();
    delete db;

}

void test() {
    shared_ptr<LegacyDatabase> p1{new LegacyDatabase(), deleter};

    shared_ptr<LegacyDatabase> p2{new LegacyDatabase(),
                                  [](LegacyDatabase *db) {
                                      cout << "Special delete 2\n";
                                      db->release();
                                      delete db;
                                  }};

}

int main() {
    test();

    return 0;
}