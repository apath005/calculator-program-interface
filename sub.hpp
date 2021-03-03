#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base
{
private:
	Base* a;
	Base* b;
	double leftOperand;
	double rightOperand;
	std::string lhs;
	std::string rhs;
public:
	Sub(Base* a, Base* b) : Base() {
		leftOperand = a->evaluate();
		rightOperand = b->evaluate();
		lhs = a->stringify();
		rhs = b->stringify();
	}
	virtual double evaluate() {
		return (leftOperand - rightOperand);
	}
	virtual std::string stringify() {
		return lhs + " - " + rhs;
	}
};
#endif
