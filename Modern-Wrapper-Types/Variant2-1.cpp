#include <iostream>
#include <variant>
#include <vector>
using namespace std;

// https://gieseanw.wordpress.com/2017/05/03/a-true-heterogeneous-container-in-c/

int main() {
	
	using VarType = variant<int, double, string>;

	auto lambda_visitor = [](auto&& arg){cout << arg<<"\n";};

	vector<VarType> vec;	// Of DIFFERNET data types!

	vec.emplace_back(1);
	vec.emplace_back(2.2);
	vec.emplace_back("hello");

	for(auto &item : vec)
		visit(lambda_visitor, item);

	return 0;
}
