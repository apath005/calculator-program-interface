#ifndef _RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

#include <cstdlib>

class Rand : public Base {
	private:
	Base* value;
    public:
        double operand;
        Rand(double value) : Base() {
		operand = value;
		value = rand() % 100;
         }
        virtual double evaluate() {
                return operand;
         }
        virtual std::string stringify() {
                return std::to_string(operand);
         }
};


#endif //__RAND_HPP__

