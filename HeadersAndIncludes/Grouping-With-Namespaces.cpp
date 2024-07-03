#include <iostream>

using namespace std;

// Global Scope. can't declare twice
int total_users = 0;

namespace OurSystem {
    // Visible globally only within OurSystem
    int total_users = 10;

    // Define ALL of your system with such name space
}

namespace DownloadedSystem {
    int total_users = 20;
}

namespace OurSystem {
    // int total_users=10;  CE

    const int SIZE = 10;
}

int main() {
    cout << OurSystem::total_users << endl;
    cout << DownloadedSystem::total_users << endl;
    cout << OurSystem::SIZE << endl;

    return 0;
}

