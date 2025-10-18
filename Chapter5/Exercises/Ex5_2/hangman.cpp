// Exercise 5.2
// Rewrite the Hangman game from Chapter 4 using functions. Include a function
// to get the player's guess and another function to determine whether the player's
// guess is in the secret word.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random> //see Chapter4/Examples/02_HighScores/highscores.cpp for explanation of why we use random
#include <cctype>

using namespace std;

string createWord();
void displayGameState(int wrong, string used, string soFar);
char getGuess(string used);
bool guessIsInWord(char guess, string word);
string updateWordSoFar(char guess, string word, string soFar);

const int MAX_WRONG = 8; // maximum number of incorrect guesses allowed

int main() {

    const string THE_WORD = createWord();
    int wrong = 0; //number of incorrect guesses
    string soFar(THE_WORD.size(), '-'); // word guessed so far
    string used = "";
    
    cout << "Welcome to Hangman. Good luck!\n";

    // main loop
    while ((wrong < MAX_WRONG && soFar != THE_WORD)) {
        displayGameState(wrong, used, soFar);

        char guess = getGuess(used);
        used += guess;

        if (guessIsInWord(guess, THE_WORD)) {
            cout << "That's right! " << guess << " is in the word.\n";

            //update soFar to include the newly guessed letter
            soFar = updateWordSoFar(guess, THE_WORD, soFar);
        }
        else {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }

    //shut down
    if (wrong == MAX_WRONG) {
        cout << "\nYou've been hanged!";
    }
    else {
        cout << "\nYou guessed it!";
    }

    cout << "\nThe word was " << THE_WORD << endl;

    return 0;
}

string createWord() {
    vector<string> words; // collection of possible words to guess;
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    random_device rd;
    mt19937 rng(rd());
    shuffle(words.begin(), words.end(), rng);
    
    return words[0];
}

void displayGameState(int wrong, string used, string soFar) {
    cout << "\n\nYou have " << MAX_WRONG - wrong;
    cout << " guesses left.\n";
    cout << "\nYou've used the following letters:\n" << used << endl;
    cout << "\nSo far, the word:\n" << soFar << endl;
}

char getGuess(string used) {
    char guess;
    cout << "\n\nEnter your guess: ";
    cin >> guess;
    guess = toupper(guess); // make uppercase since secret word is uppercase
    while (used.find((guess)) != string::npos) {
        cout << "\nYou've already guessed " << guess << endl;
        cout << "Enter your guess: ";
        cin >> guess;
        guess = toupper(guess);
    }
    return guess;
}

bool guessIsInWord(char guess, string word) {
    return word.find(guess) != string::npos;
}

string updateWordSoFar(char guess, string word, string soFar) {
    for (unsigned int i = 0; i < word.length(); ++i) {
        if (word[i] == guess) {
        soFar[i] = guess;
        }
    }
    return soFar;
}