// Exercise 5.3 v1
// Using default arguments, write a function that asks the user for a 
// number and returns that number. The function should accept a string prompt from
// the calling code. If the caller doesn't supply a string for the prompt, the function
// should user a generic prompt. Next, using function overloading, write a function that
// achieves the same result
//
// This implementation uses default arguments

#include <iostream>
#include <string>

using namespace std;

int getNumber(string prompt = "Enter a Number: ");

// test driver

int main() {

    // testing with default argument
    cout << getNumber() << endl;

    //testing with provided prompt
    cout << getNumber("What number are you thinking of?\n") << endl;

    return 0;
}

int getNumber(string prompt) {
    int number;
    cout << prompt;
    cin >> number;
    return number;
}