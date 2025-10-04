// Word Jumble
// The classic word jumble game where the player can ask for a hint

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    //define the dictionary and hints
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] = {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"laboured", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what this game is all about."}
    };

    //select the word
    srand(static_cast<unsigned int>(time(0)));
    int choice = rand() % NUM_WORDS;
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];

    //jumble the word

    string jumble = theWord;
    int length = jumble.size();
    for (int i = 0; i < length; ++i) {
        int index1 = rand() % length;
        int index2 = rand() % length;
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    //Welcome the player
    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";

    cout << "The jumble is: " << jumble << endl;

    string guess;
    cout << "\nYour guess: ";
    cin >> guess;

    //game loop
    while(guess != theWord && guess != "quit") {
        if (guess == "hint") {
            cout << theHint;
        }
        else {
            cout << "Sorry, that's not it.\n";
        }
        cout << "\nYour guess: ";
        cin >> guess;
    }

    //saying goodbye
    if (guess == theWord) {
        cout << "\nThat's it! You guessed the word!\n";
    }
    cout << "\nThanks for playing.\n";

    return 0;
}