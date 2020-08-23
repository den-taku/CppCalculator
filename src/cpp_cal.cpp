#include <iostream>
#include <cstring>
#include <string>
#include "stack.h"
#include "rpn.h"
#include "operator.h"
#include "calculator.h"
using namespace std;

int main() {
    cout << "Hello! Let's calculate!!" << endl;
    cout << "Input expression like 1+(2*3)/4-5" << endl;
    cout << "※ when you want to divide or subtract in succession, "
         << "please use () explicitly." << endl;
    string input;
    getline(cin, input);
    Calculator cal(input.c_str());
}
































































































