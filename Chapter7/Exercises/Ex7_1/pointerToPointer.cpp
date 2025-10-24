//Exercise 7.1
// Write a program with a pointer to a pointer to a `string` object
// Use the pointer to call the `size()` member function of the `string` object


#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello, World!";
    string* pStr = &s;
    string** ppStr = &pStr;

    cout << "s: " << s << "\n";
    cout << "pStr: " << pStr << "\n";
    cout << "*pStr: " << *pStr << "\n";
    cout << "ppStr: " << ppStr << "\n";
    cout << "*ppStr: " << *ppStr << "\n";
    cout << "**ppStr: " << **ppStr << "\n\n";

    cout << "s.size(): " << s.size() << "\n";
    cout << "pStr->size(): " << pStr->size() << "\n";
    cout << "(*ppStr)->size(): " << (*pStr).size() << "\n";

    return 0;
}