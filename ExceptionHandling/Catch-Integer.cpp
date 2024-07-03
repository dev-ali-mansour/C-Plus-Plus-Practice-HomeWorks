#include <iostream>

using namespace std;

// Create a dynamic array
// Throws 3 possible exceptions
int *CreateArrayOnMobile(int len) {
    if (len <= 0)
        throw 17;   // Some error code

    if (len >= 10000)
        throw runtime_error("Too big array for this mobile memory!");
    return new int[len];
}

int main() {
    int *p = nullptr;
    try {
        int *p = CreateArrayOnMobile(-10);
    }catch (int &error_code){
        cout<<"Error Code: "<<error_code;
    } catch (invalid_argument &e) {
        cout << "invalid_argument: " << e.what();
    } catch (runtime_error &e) {
        cout << "runtime_error: " << e.what();
    } catch (...) {
        cout << "Caught unknown exception type!\n";
    }
    if (p != nullptr) { // Only if created
        delete[]p;
        p = nullptr;
    }

    return 0;
}