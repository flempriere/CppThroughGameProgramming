// Exercise 6.3
// What's wrong with the following function?
//
// ```cpp
//int& plusThree(int number) {
//  int threeMore = number + 3;
//  return threeMore;
//}
// The function attempts to return a reference to a local variable
// `threeMore`, which will go out of lifetime at the end of the function.
// Hence the reference is invalid

#include <iostream>

int& plusThree(int number);

int main() {

    int number = 0;
    std::cout << "number: " << number << std::endl;
    std::cout << "number + 3: " << plusThree(number) << std::endl;
    
    return 0;
}

int& plusThree(int number) {
    int threeMore = number + 3;
    return threeMore;
}