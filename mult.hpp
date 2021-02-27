#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
private:
    Base* a ;
    Base* b ;
public:
    Mult(Base* a, Base* b) : Base() { 
	this->a = a; 
	this->b = b; 
	}
    	virtual double evaluate() { 
		return a->evaluate() * b->evaluate(); 
	}
    	virtual std::string stringify() { 
		return (a->stringify() + " * " + b->stringify()); 
	}
};

#endif //__MULT_HPP__

