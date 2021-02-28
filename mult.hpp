#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base
{
private:
	Base* a;
	Base* b;
	double leftOperand;
	double rightOperand;
	std::string lhs;
	std::string rhs;
public:
	Mult(Base* a, Base* b) : Base() {
		leftOperand = a->evaluate();
		rightOperand = b->evaluate();
		lhs = a->stringify();
		rhs = b->stringify();
	}
	virtual double evaluate() {
		return (leftOperand * rightOperand);
	}
	virtual std::string stringify() {
		return lhs + " * " + rhs;
	}
};
#endif