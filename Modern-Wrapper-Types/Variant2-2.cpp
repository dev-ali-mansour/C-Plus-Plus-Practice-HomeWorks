#include <iostream>
#include <variant>
#include <vector>
using namespace std;

// https://gieseanw.wordpress.com/2017/05/03/a-true-heterogeneous-container-in-c/

template <class VARIANT>
struct VariantContainer
{
	vector<VARIANT> objects;

    template <class V>
    void visit(V&& visitor) {
        for (auto& object : objects)
            std::visit(visitor, object);	// same name: use std::
    }

    template <class V>
    void push_back(V&& item) {
    	objects.push_back(item);
    }

    template <class... Args>
    void emplace_back(Args&&... args) {
    	objects.emplace_back(args...);
    }
};

int main() {
	using VarType = variant<string, int>;

	VariantContainer<VarType> container;
	container.emplace_back("hello");
	container.emplace_back(1000);

	container.visit(
		[](auto&& arg){cout << arg<<"\n";}
	);

	return 0;
}
