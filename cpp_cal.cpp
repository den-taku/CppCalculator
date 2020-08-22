#include <iostream>
#include <cstring>
using namespace std;

class Calculator {
    public:
        Calculator(char input[]);
        void print_for_test();
    private:
        char input_str[256];
};

Calculator::Calculator(char input[]) {
    strcpy(input_str, input);
}

void Calculator::print() {
    cout << input_str << endl;
}

int main() {
    Calculator cal("hoge\n");
    cal.print_for_test();
    cout << "Hello, world!" << endl;
}
































































































