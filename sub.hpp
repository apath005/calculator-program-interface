#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
private:
    Base* a ;
    Base* b ;
public:
    Sub(Base* a, Base* b) : Base() { 
	this->a = a; 
	this->b = b; 
	}
    	virtual double evaluate() { 
		return a->evaluate() - b->evaluate(); 
	}
    	virtual std::string stringify() { 
		return (a->stringify() + " - " + b->stringify());
	}
};

#endif //__SUB_HPP__

