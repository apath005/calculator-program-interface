#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include<math.h>
#include<cmath>

class Op : public Base {
    public:
	double operand;
        Op(double value) : Base() { 
                operand = value;
        }
        virtual double evaluate() {
                return operand;
        }
        virtual std::string stringify() {
                return std::to_string(operand);
        }
};
#endif //__OP_HPP__
