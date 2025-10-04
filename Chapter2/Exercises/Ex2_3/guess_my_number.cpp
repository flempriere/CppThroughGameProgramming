// Exercise 2.3
// Write a new version of the Guess My Number program in which the play and the computer switch roles.
// That is, the player picks a number and the computer must guess what it is.

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main() {
    srand(static_cast<unsigned int>(time(0))); // seed the random number generator;

    cout << "\tWelcome to Guess My Number\n";
    
    //Making min and max valid numbers constants so easy to change
    const int MIN_GUESS = 1;
    const int MAX_GUESS = 100;

    //get a number in the valid range from the player
    int secretNumber;
    do {
        cout << "\nEnter a number between " << MIN_GUESS;
        cout << " and " << MAX_GUESS << ": ";
        cin >> secretNumber;
    } while (secretNumber < MIN_GUESS || secretNumber > MAX_GUESS);

    int lowest = MIN_GUESS;
    int highest = MAX_GUESS;

    int tries = 0;
    int guess;

    do {
        if (highest == lowest) {
            guess = highest;
        }
        else {
          guess = rand() % (highest - lowest) + lowest + 1;
        }
        ++tries;

        cout << "Computer guessed " << guess << endl;
        if (guess > secretNumber) {
            cout << "Too high!\n\n";
            highest = guess - 1;
        }
        else if (guess < secretNumber) {
            cout << "Too low!\n\n";
            lowest = guess + 1;
        }
        else {
            cout << "\nThat's it! Computer got it in " << tries << " guesses!\n";
        }
    } while(guess != secretNumber);

    return 0;
}

