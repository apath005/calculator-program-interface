#ifndef __RAND_HPP__
#define __OP_HPP__

#include "base.hpp"

class Rand : public Base
{
private:
	double value;
public:
	Rand(double value) : Base() {
		srand(time(0));
		this->value = rand() % 100;
	}
	virtual double evaluate() {
		return this->value;
	}
	virtual std::string stringify() {
		return std::to_string(this->value);
	}
};
#endif //__RAND_HPP__
