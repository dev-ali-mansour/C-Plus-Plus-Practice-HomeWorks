#include <iostream>

namespace OurSystem {
    namespace Customer {
        int limit = 1;
    }
    namespace Admin {
        int limit = 10;
    }
}

// C++17 simplifies nested namespaces
/*
namespace OurSystem::Customer {
    int limit = 1;
}
 */

int main() {
    std::cout << OurSystem::Customer::limit << std::endl;
    namespace scope = OurSystem::Customer;  // alias
    std::cout << scope::limit << std::endl;

    return 0;
}