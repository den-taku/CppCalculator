#include <iostream>
#include <cstring>
#include <string>
#include "stack.h"
#include "rpn.h"
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

class Operator {
    public:
        Operator(const char input[]);
        void calculate();
    private:
        char str[256];
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

Operator::Operator(const char input[]) {
    strcpy(str, input);
}

void Operator::calculate() {
    float answer = 0;
    // calulate as RPN -> answer
    cout << answer << endl;
}

int main() {
    cout << "Hello! Let's calculate!!" << endl;
    cout << "Input expression like 1+(2*3)/4-5" << endl;
    string input;
    getline(cin, input);
    Calculator cal(input.c_str());
}
































































































