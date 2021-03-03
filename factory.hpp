#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include <queue>
#include <stack>
#include <iostream>
#include <cstring>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
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
	std::queue<std::string> q;
	std::stack<std::string> s;
	std::queue<Base*> q2;
	Base* temp2 = temp2;
	Base* temp3 = temp3;

        for (int i = 1; i < length; ++i) {
        a = static_cast<std::string>(input[i]);
          if (isdigit(a.at(0))) {
            q.push(input[i]);
        }
          else if (a == "+" || a == "-" || a == "*" || a == "/" || a == "**") {
            while(!s.empty()){
              q.push(s.top());
              s.pop();
        }
            s.push(input[i]);
        }
          else {
          cout << "ERROR: invalid input" << endl;
          return nullptr;
        }
        }

        while(!s.empty()){
          q.push(s.top());
          s.pop();
        }

       	while(!q.empty()){
       	a = static_cast<std::string>(q.front());
      	if (a == "+") {
    	   temp2 = q2.front();
	   q2.pop();
 	   temp3 = q2.front();
	   q2.pop();
     	   q2.push(new Add(temp2, temp3));
	   delete temp2, temp3;
      	   q.pop();
          }
          else if (a == "-") {
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           q2.push(new Sub(temp2, temp3));
	   delete temp2, temp3;
           q.pop();
          }
          else if (a == "*"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           q2.push(new Mult(temp2, temp3));
	   delete temp2, temp3;
           q.pop();
          }
          else if (a == "/"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           q2.push(new Div(temp2, temp3));
	   delete temp2, temp3;
           q.pop();
          }
          else if (a == "**"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           q2.push(new Pow(temp2, temp3));
	   delete temp2, temp3;
           q.pop();
          }
          else {
           q.pop();
           q2.push(new Op(stod(a)));
          }
	}

        return q2.front();
	return 0;
      }
};

#endif
