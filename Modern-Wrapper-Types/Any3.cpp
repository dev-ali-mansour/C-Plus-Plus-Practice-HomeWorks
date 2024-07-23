#include <iostream>
#include <any>
#include <map>
#include <string>
using namespace std;


int main() {

	map<string, any> mp;
	mp["integer"] = 10;
	mp["string"] = string("Hello World");
	//m["string"] = "Hello World";		// careful: const char* not string
	mp["float"] = 1.0;

	for (auto &pair : mp) {
		auto &val = pair.second;

	    if (val.type() == typeid(int))
	        cout << "int: " << any_cast<int>(val) << "\n";
	    else if (val.type() == typeid(string))
	        cout << "string: " << any_cast<string>(val) << "\n";
	    else if (val.type() == typeid(double))
	        cout << "float: " << any_cast<double>(val) << "\n";
	}
	return 0;
}
