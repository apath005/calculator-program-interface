#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base
{
private:
	Base* a;
	Base* b;
	double leftOperand;
	double rightOperand;
	std::string lhs;
	std::string rhs;
public:
	Add(Base* a, Base* b) : Base() {
		leftOperand = a->evaluate();
		rightOperand = b->evaluate();
		lhs = a->stringify();
		rhs = b->stringify();
	}
	virtual double evaluate() {
		return (leftOperand + rightOperand);
	}
	virtual std::string stringify() {
		return lhs + " + " + rhs;
	}
};
#endif //__ADD_HPP__
