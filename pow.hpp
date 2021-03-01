#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"

#include<cmath>

class Pow : public Base
{
private:
	Base* a;
	Base* b;
	double leftOperand;
	double rightOperand;
	std::string lhs;
	std::string rhs;
public:
	Pow(Base* a, Base* b) : Base() {
                this->a = a;
                this->b = b;
		leftOperand = a->evaluate();
		rightOperand = b->evaluate();
		lhs = a->stringify();
		rhs = b->stringify();
	}
	virtual double evaluate() {
		return std::pow(leftOperand, rightOperand);
	}
	virtual std::string stringify() {
		return lhs + " ** " + rhs;
	}
};
#endif
