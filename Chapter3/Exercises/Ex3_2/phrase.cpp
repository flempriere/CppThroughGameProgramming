// Exercise 3.2
// What is wrong with the following code?
//
//for (int i = 0; i <= phrase.size(); ++i) {
//    cout << "Character at position " << i << " is: " << phrase[i] << endl;
//}
// the index size in a string stores a character referred to as the null terminator
// this is not an actual part of the string, but a character designed to indicate the
// end of the string has been reached. We don't want to print this!


#include <iostream>
#include <string>

using namespace std;

int main() {
    string phrase = "A test phrase";
    for (unsigned int i = 0; i <= phrase.size(); ++i) {
        cout << "Character at position " << i << " is " << phrase[i] << endl;
    }
    return 0;
}