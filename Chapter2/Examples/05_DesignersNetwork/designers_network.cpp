// Designers Network
// Demonstrates logical operators

#include <iostream>
#include <string>

using namespace std;

int main() {
    string username;
    string password;
    bool success;

    cout << "\tGame Designer's Network\n";

    do {
        cout << "\nUsername: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        if (username == "S.Meier" && password == "civilisation") {
            cout << "\nHey, Sid.\n";
            success = true;
        }
        else if (username == "S.Miyamoto" && password == "mariobros") {
            cout << "\nWhat's up, Shigeru?\n";
            success = true;
        }
        else if (username == "W.Wright" && password == "thesims") {
            cout << "\nHow goes it, Will?\n";
            success = true;
        }
        else if (username == "guest" || password == "guest") {
            cout << "Welcome, guest.\n";
            success = true;
        }
        else {
            cout << "\nYour login failed.";
            success = false;
        }
    } while (!success);

    return 0;
}