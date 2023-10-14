#include <iostream>

using namespace std;

pair gp{5, 6};

//pair<int, int> &F_by_ref() { return gp; }
auto &F_by_ref() { return gp; }

auto F_by_val() { return gp; }

int main() {
//    pair<int, string> p{33, "belal"};

//    auto p = pair(33, "Belal");     //Template Argument Deduction

    pair p(33, "Belal");        //Template Argument Deduction

    auto &[sal4, str4] = p;
    auto &[x1, y1] = F_by_ref();            // & for return by reference
//    auto &[x1,y1]=F_by_val();                     // CE

    auto [x2, y2] = F_by_val();             // Ok, just waste of time/memory
    auto &&[x3, y3] = F_by_val();           // && for revalue ref (later in semantic moves)

    return 0;
}