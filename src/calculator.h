#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <iostream>
#include <cstring>
#include <string>
#include "stack.h"
using namespace std;

class Calculator {
    public:
        Calculator(const char input[]);
        void print_for_test();
        void print_for_test_n();
    private:
        char str[256];
        char notated_str[256];
};

Calculator::Calculator(const char input[]) {
    // initialize Calculator
    strcpy(str, input);
    print_for_test();
    cout << " = " << flush;

    // renotate input as Reverse Polish Notation
    RPN rpn(str);
    rpn.notate(notated_str);

    // calculate notated_str and print result
    Operator oper(notated_str);
    oper.calculate();
}

void Calculator::print_for_test() {
    cout << str << flush;
}

void Calculator::print_for_test_n() {
    cout << notated_str << endl;
}

#endif
