// Exercise 1.2
// What is displayed by each line in the following code snippet Explain each result.
//
// cout << "Seven divided by three is " << 7 / 3 << endl;
// cout << "Seven divided by three is " << 7.0 / 3 << endl;
// cout << "Seven divided by three is " << 7.0 / 3.0 << endl;

#include <iostream>

using namespace std;

int main() {

    cout << "Seven divided by three is " << 7 / 3 << endl;
    cout << "Seven divided by three is " << 7.0 / 3 << endl;
    cout << "Seven divided by three is " << 7.0 / 3.0 << endl;

    return 0;
}