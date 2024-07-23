#include <iostream>
#include <variant>
using namespace std;


struct PrintVisitor {
   template <class T>
   void operator()(T&& arg) {
		cout << arg<<"\n";
   }
};

int main() {
	using VarType = variant<int, double, string>;
	VarType var("Mostafa");

	auto lambda_visitor = [](auto&& arg){cout << arg<<"\n";};

	visit(lambda_visitor, var);

	return 0;
}
