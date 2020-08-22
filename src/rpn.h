#ifndef RPN_H_
#define RPN_H_

#include <iostream>
#include <cstring>
#include <string>
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
    try {
        for(int i = 0, j = 0; i < 256; i++) {
            // process operators
            if(str[i] == '+') {
                stack.push('+');
            } else if(str[i] == '-') {
                stack.push('-');
            } else if(str[i] == '*') {
                if(stack.top() == '+' || stack.top() == '-') {
                    buffer[j] = '*';
                    ++j;
                } else {
                    stack.push('*');
                }
            } else if(str[i] == '/') {
                if(stack.top() == '+' || stack.top() == '-') {
                    buffer[j] = '/';
                    ++j;
                } else {
                    stack.push('/');
                }
            } else if(str[i] == '(') {
                stack.push('(');
            } else if(str[i] == ')') {
                while(stack.top() != '(') {
                    char tmp = stack.top();
                    buffer[j] = tmp;
                    ++j;
                    stack.pop();
                }
                stack.pop();
            } 
            // process number
              else if(str[i] >= '0' && str[i] <= '9') {
                buffer[j] = str[i];
                ++j;
            } else if (str[i] == '\0' || str[i] == '\n' || str[i] == ' ') {
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
    strcpy(output, buffer);
}


#endif



































































































