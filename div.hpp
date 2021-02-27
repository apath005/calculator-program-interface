#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
private:
    Base* a ;
    Base* b ;
public:
    Div(Base* a, Base* b) : Base() {
        this->a = a;
        this->b = b;
	}
        virtual double evaluate() {
		return a->evaluate() / b->evaluate(); 
	}
        virtual std::string stringify() {
        	return (a->stringify() + " / " + b->stringify());
	}
};

#endif //__DIV_HPP__
