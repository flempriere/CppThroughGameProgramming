// Play Again 2.0
// Demonstrates do loops

#include <iostream>

using namespace std;

int main() {
    char again;
    do {
        cout << "\n**Played an exciting game**\n";
        cout << "Do you want to play again? (y/n): ";
        cin >> again;
    } while (again == 'y');

    cout << "\nOkay, bye." << endl;

    return 0;
}