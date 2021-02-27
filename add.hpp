#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base {
private:
    Base* a ;
    Base* b ;
public:
    Add(Base* a, Base* b) : Base() { 
	this->a = a; 
	this->b = b; 
	}
        virtual double evaluate() { 
		return a->evaluate() + b->evaluate(); 
	}
        virtual std::string stringify() { 
		return (a->stringify() + " + " + b->stringify()); 
	}
};

#endif //__ADD_HPP__
