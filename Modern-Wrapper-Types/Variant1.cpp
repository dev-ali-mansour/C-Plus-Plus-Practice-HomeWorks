#include<iostream>
#include<variant>
using namespace std;

int main() {

	variant<string, int> var(10);
	cout<<get<1>(var)<<"\n";	// 10
	cout<<get<int>(var)<<"\n";	// 10
	cout<<var.index()<<"\n";	// 1

	// Exceptionbad_variant_access:
	//auto str = get<string>(var);	only int is available now
	//auto val = get<0>(var);

	//auto d = get<double>(var);	// CE no double available
	//auto d = get<5>(var);			// CE invalid index

	// Get pointer to the variable
	auto ptr1 = get_if<int>(&var);	// must &
	cout<<*ptr1<<"\n";	// 10
	auto ptr2 = get_if<string>(&var);
	cout<<ptr2<<"\n";	// 0 (nullptr)

	var = 10;	// create temp, then assign
	get<int>(var) = 20;		// assign in the reference directly (efficient)

	// use another type
	//get<string>(var) = "ali";	// CE
	var = "ali";
	cout<<var.index()<<"\n";	// 0


	return 0;
}
