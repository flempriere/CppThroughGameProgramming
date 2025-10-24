// Exercise 7.3
// Will the three memory addresses displayed by the following program all
// be the same? Explain what's going on with the code.
//
// The memory will be the same in all cases, as the statements are all equivalent
// to &a

#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int& b = a;
    int* c = &b;

    cout << &a << endl;
    cout << &b << endl;
    cout << &(*c) << endl;

    return 0;
}