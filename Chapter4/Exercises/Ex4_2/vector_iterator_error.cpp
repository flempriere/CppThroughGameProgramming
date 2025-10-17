// Exercise 4.2
// Assuming that scores is a vector that holds elements of type int, what's
// wrong with the following code snippet (meant to increment each element)?

#include <vector>
#include <iostream>


int main() {
    std::vector<int> scores;
    for (int i = 0; i < 10; i++) {
        scores.push_back(i);
    }
    std::vector<int>::iterator iter;
    //increment each score
    for (iter = scores.begin(); iter != scores.end(); ++iter) {
        iter++;
    }
    //print the vector contents after the operation
    for (iter = scores.begin(); iter != scores.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
    return 0;
}