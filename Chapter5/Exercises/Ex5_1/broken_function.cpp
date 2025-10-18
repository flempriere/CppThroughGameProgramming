// Exercise 5.1
// What's wrong with the following prototype?
// int askNumber(int low = 1, int high);


#include <iostream>

int askNumber(int low = 1, int high);


int main() {
    int num;

    num = askNumber(5);
    std::cout << "You entered: " << num << std::endl;

    return 0;
}

int askNumber(int low = 1, int high) {
    int num;
    do {
        std::cout << "Enter a number in [" << low << "," << high << "]: " << std::endl;
        std::cin >> num;
    } while(num < low || num > high);
    return num;
}