// Exercise 4.1
// Write a program using vectors and iterators that allows a user
// to maintain a list of his or her favourite games. The program
// should allow the user to list all game titles, add a game title and remove a game title

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {

    vector<string> games;
    vector<string>::const_iterator iter;

    enum options {LIST = 1, ADD, REMOVE, HELP, QUIT};

    cout << "\t\tGames List\n\n";
    cout << "Options:\n\n";
    cout << "1 - List all Games\n";
    cout << "2 - Add a Game\n";
    cout << "3 - Remove a Game\n";
    cout << "4 - See the Menu again\n";
    cout << "5 - Quit\n";
    cout << "Warning: Titles must be one word!\n";

    int option;
    do {
        cout << "\n>>: ";
        cin >> option;
        string title;
        switch(option) {
            case LIST:
                for (iter = games.begin(); iter != games.end(); ++iter) {
                    cout << *iter << endl;
                }
                break;
            case ADD:
                cout << "Enter Game Title: ";
                cin >> title;
                games.push_back(title);
                break;
            case REMOVE:
                cout << "Enter Game Title: ";
                cin >> title;
                iter = std::find(games.begin(), games.end(), title);
                if (iter != games.end()) {
                    games.erase(iter);
                } else {
                    cout << "Could not find that game!" << endl;
                }
                break;
            case QUIT:
                break;
            default:
                cout << "Invalid option!" << endl;
                [[fallthrough]];    // fallthrough attribute tells the compiler 
                                    // the missing break here is intentional
            case HELP:
              cout << "Options:\n\n";
              cout << "1 - List all Games\n";
              cout << "2 - Add a Game\n";
              cout << "3 - Remove a Game\n";
              cout << "4 - See the Menu again\n";
              cout << "5 - Quit\n";
              cout << "Warning: Titles must be one word!\n";
              break;
            }
    } while(option != QUIT);
    
    return 0;
}