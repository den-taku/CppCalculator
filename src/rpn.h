#ifndef RPN_H_
#define RPN_H_

#include <iostream>
#include <cstring>
#include <string>
#include "stack.h"
using namespace std;

class RPN {
    public:
        RPN(const char input[]);
        void notate(char output[]);
    private:
        char str[256];
};

RPN::RPN(const char input[]) {
    strcpy(str, input);
}

void RPN::notate(char output[]){
    char buffer[256];
    // str -> RPN -> buffer
    Stack<char> stack(256);
    int j = 0;
    try {
        for(int i = 0, after_ = 0; i < 256; i++) {
            // process operators
            if(str[i] == '+') {
                if(!after_){
                    buffer[j] = '|';
                    ++j;
                }
                if(stack.top() == '*' || stack.top() == '/') {
                    while(stack.top() == '*' || stack.top() == '/') {
                        buffer[j] = stack.top();
                        ++j;
                        stack.pop();
                    }
                }
                stack.push('+');
                after_ = 0;
            } else if(str[i] == '-') {
                if(!after_){
                    buffer[j] = '|';
                    ++j;
                }
                if(stack.top() == '*' || stack.top() == '/') {
                    while(stack.top() == '*' || stack.top() == '/') {
                        buffer[j] = stack.top();
                        ++j;
                        stack.pop();
                    }
                }
                stack.push('-');
                after_ = 0;
            } else if(str[i] == '*') {
                if(after_) {
                    stack.push('*');
                } else {
                    buffer[j] = '|';
                    ++j;
                    if(stack.top() == '+' || stack.top() == '-') {
                        buffer[j] = '*';
                        ++j;
                    } else {
                        stack.push('*');
                    }
                }
                after_ = 0;
            } else if(str[i] == '/') {
                if(after_) {
                    stack.push('/');
                } else {
                    buffer[j] = '|';
                    ++j;
                    if(stack.top() == '+' || stack.top() == '-') {
                        buffer[j] = '/';
                        ++j;
                    } else {
                        stack.push('/');
                    }
                }
                after_ = 0;
            } else if(str[i] == '(') {
                stack.push('(');
                after_ = 0;
            } else if(str[i] == ')') {
                buffer[j] = '|';
                ++j;
                while(stack.top() != '(') {
                    char tmp = stack.top();
                    buffer[j] = tmp;
                    ++j;
                    stack.pop();
                }
                stack.pop();
                after_ = true;
            } 
            // process number
              else if(str[i] >= '0' && str[i] <= '9') {
                buffer[j] = str[i];
                ++j;
            } else if (str[i] == '\0' || str[i] == '\n' || str[i] == ' ') {
                buffer[j] = '|';
                ++j;
                while(!stack.empty()) {
                    buffer[j] = stack.top();
                    ++j;
                    stack.pop();
                }
                break;
            } else {
                cout << buffer << endl;
                cout << str[i] << endl;
                cout << "Maybe input error. Please retry." << endl;
                std::exit(1);
            }
        }
    } catch (const overflow_error& e) {
        cerr << e.what() << endl;
    } catch (const underflow_error& e) {
        cerr << e.what() << endl;
    }
    buffer[j] = '\0';
    strcpy(output, buffer);
}

#endif
