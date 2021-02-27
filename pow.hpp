#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"

#include<math.h>

#include<cmath>

class Pow : public Base {
private:
    Base* a ;
    Base* b ;
public:
    Pow() : Base() {}
    Pow(Base* a, Base* b) : Base() {
        this->a = a;
        this->b = b;
	}
	virtual double evaluate() {
        	return std::pow(a->evaluate(), b->evaluate()); 
	}
	virtual std::string stringify() {
        	return (a->stringify() + " ** " + b->stringify());
	}
};

#endif //__POW_HPP__
