#include <iostream>
#include <vector>
#include <optional>
using namespace std;

// https://www.bfilipek.com/2018/07/in-place-cpp17.html

struct Employee {
	Employee(string name, int salary)  {
		cout<<"Employee\n";
	}
	~Employee() {
		cout<<"~Employee\n";
	}
	Employee(const Employee &e) = delete;
	Employee(Employee &&e) = delete;
};

int main() {
	auto emp = make_optional<Employee>("Hani", 20);
	/*
		~Employee
		~Employee
	 */

	auto opt1 = make_optional<vector<int>>({4, 1, 20, 30});
	auto opt2 = make_optional<vector<int>>(4, 1);

	return 0;
}
/*
  template<typename _Tp, typename _Up, typename ..._Args>
    constexpr optional<_Tp>
    make_optional(initializer_list<_Up> __il, _Args&&... __args)
    { return optional<_Tp> { in_place, __il, std::forward<_Args>(__args)... }; }
    // Mandatory copy elision from C++17: there is no temporary object involved.
 */
