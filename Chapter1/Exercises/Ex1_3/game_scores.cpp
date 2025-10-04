// Exercise 1.3
// Write a program that gets three game scores from the user and displays the average
// Note: For simplicity we will work with integer scores and assume the fractional part is lost

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

    int score1, score2, score3;
    int n_scores = 3.0;

    cout << "Enter three integer scores each seperated by a new line" << endl;

    cin >> score1;
    cin >> score2;
    cin >> score3;

    cout << "The average score is: " << (score1 + score2 + score3) / n_scores << endl;
    
    return 0;
}