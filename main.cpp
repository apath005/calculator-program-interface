#include <iostream>
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "mult.hpp"
#include "factory.hpp"
#include "base.hpp"
#include <string>

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