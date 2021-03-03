#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base
{
private:
	Base* a;
	Base* b;
	double leftOperand;
	double rightOperand;
	std::string lhs;
	std::string rhs;
public:
	Div(Base* a, Base* b) : Base() {
		this->a = a;
                this->b = b;
		leftOperand = a->evaluate();
		rightOperand = b->evaluate();
		lhs = a->stringify();
		rhs = b->stringify();
	}
	virtual double evaluate() {
		return (leftOperand / rightOperand);
	}
	virtual std::string stringify() {
		return lhs + " / " + rhs;
	}
};
#endif
