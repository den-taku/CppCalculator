#ifndef OPERATOR_H_
#define OPERATOR_H_

#include <iostream>
#include <cstring>
#include <string>
#include "stack.h"
using namespace std;

class Operator {
    public:
        Operator(const char input[]);
        void calculate();
    private:
        char str[256];
};

Operator::Operator(const char input[]) {
    strcpy(str, input);
}

void Operator::calculate() {
    float answer = 0;
    // calulate as RPN -> answer
    Stack<float> stack(256);
    Stack<int> num(256);
    // cout << str << endl;
    for(int i = 0, j = 0; i < 256; ++i) {
        if(str[i] == '\0') {
            answer = stack.top();
            stack.pop();
            break;
        } else if (str[i] >= '0' && str[i] <= '9'){
            ++j;
            // cout << "index" << j << endl;
            // cout << "encode" << static_cast<int>(str[i] - '0') << endl;
            num.push(static_cast<int>(str[i] - '0'));
        } else if (str[i] == '|') {
            float buf = 0.0;
            for(int k = 1; j > 0; k *= 10) {
                // cout << "k" << k << endl;
                // cout << "j" << j << endl;
                buf += static_cast<float>( k * num.top() );
                num.pop();
                --j;
            }
            // cout << buf << endl;
            stack.push(buf);
        } else if (str[i] == '+') {
            auto buf1 = stack.top();
            stack.pop();
            auto buf2 = stack.top();
            stack.pop();
            // cout << "RESULT " << buf2 + buf1 << endl;
            // if(!stack.empty()){
            //     cout <<"BEFORE + stack.top() = " << stack.top() << endl;
            // }
            stack.push( buf2 + buf1 );
            // cout <<"AFTER + stack.top() = " << stack.top() << endl; 
        } else if (str[i] == '-') {
            auto buf1 = stack.top();
            stack.pop();
            auto buf2 = stack.top();
            stack.pop();
            stack.push( buf2 - buf1 );
        } else if (str[i] == '*') {
            auto buf1 = stack.top();
            stack.pop();
            auto buf2 = stack.top();
            stack.pop();
            stack.push( buf2 * buf1 );
        } else if (str[i] == '/') {
            auto buf1 = stack.top();
            stack.pop();
            auto buf2 = stack.top();
            stack.pop();
            // cout << buf2 / buf1 << "/" << endl; // diveide
            stack.push( buf2 / buf1 );
        }
    }


    cout << answer << endl;
}

#endif
