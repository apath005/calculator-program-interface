#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <queue>
#include <stack>

#include "base.hpp"

#include "op.hpp"

#include "rand.hpp"

#include "add.hpp"

#include "sub.hpp"

#include "mult.hpp"

#include "div.hpp"

#include "pow.hpp"

using std::cout;
using std::endl;

class Base;

class Factory {
public:
	Base* parse(char** input, int length){
	std::string a;
	std::queue<std::string> queue;
	std::stack<std::string> stack;
	std::queue<Base*> q2;
	Base* temp2 = temp2;
	Base* temp3 = temp3;

        for (int i = 1; i < length; ++i){
        a = std::string(input[i]);
          if (isdigit(a.at(0))){
            queue.push(input[i]);
        }
          else if (a == "+" || a == "-" || a == "*" || a == "/" || a == "**"){
            while(!stack.empty()){
              queue.push(stack.top());
              stack.pop();

        }
            stack.push(input[i]);
        }
          else {
          cout << "ERROR: invalid input" << endl;
          return nullptr;
        }
        }

        while(!stack.empty()){
          queue.push(stack.top());
          stack.pop();
        }

       	while(!queue.empty()){
       	a = std::string(queue.front());
      	if (a == "+") {
    	   temp2 = q2.front();
	   q2.pop();
 	   temp3 = q2.front();
	   q2.pop();
     	   q2.push(new Add(temp2, temp3));
	   delete temp2; 
	   delete temp3;
      	   queue.pop();
          }
          else if (a == "-") {
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           q2.push(new Sub(temp2, temp3));
	   delete temp2; 
	   delete temp3;
           queue.pop();
          }
          else if (a == "*"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           q2.push(new Mult(temp2, temp3));
	   delete temp2; 
	   delete temp3;
           queue.pop();
          }
          else if (a == "/"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           q2.push(new Div(temp2, temp3));
	   delete temp2; 
	   delete temp3;
           queue.pop();
          }
          else if (a == "**"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           q2.push(new Pow(temp2, temp3));
	   delete temp2; 
	   delete temp3;
           queue.pop();
          }
          else {
           queue.pop();
           q2.push(new Op(stod(a)));
          }
	}
        return q2.front();
        return 0;
      }
};


#endif
