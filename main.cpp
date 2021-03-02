#include <iostream>

#include<string>

#include "base.hpp"

#include "factory.hpp"

using std::cout;
using std::endl;

int main(int argc, char**argv) {
	Factory* expression = new Factory();
        for(unsigned i = 1; i < argc; i++) {
		cout << argv[i] << endl;
	}
	delete expression;

	Base* result = expression->parse(argv, argc);
	if(!result) {
		cout << "ERROR: invalid expression" << endl;
	} else {
		cout << result->stringify() << " = " << result->evaluate() << endl;
	}
	delete result;
	return 0;
};
