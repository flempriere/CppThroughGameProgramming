// Exercise 2.2
// Whats wrong with the following loop
// int x = 0
// while(x) {
// ++x
// cout << x << endl
//}

#include <iostream>

using namespace std;

int main() {
    int x = 0;
    while (x) {
        ++x;
        cout << x << endl;
    }
    return 0;
}