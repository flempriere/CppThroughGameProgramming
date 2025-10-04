// Hero's Inventory 2.0
// Demonstrates array initialisation using initialiser lists

#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX_ITEMS = 3;
    string inventory[] = {"sword", "armor", "shield"};
    int numItems = MAX_ITEMS;

    cout << "Your items:\n";
    for (int i = 0; i < numItems; ++i) {
        cout << inventory[i] << endl;
    }
    
    cout << "\nYou trade your sword for a battle axe.\n";
    inventory[0] = "battle axe";

    cout << "Your items:\n";
    for (int i = 0; i < numItems; ++i) {
      cout << inventory[i] << endl;
    }

    cout << "\nThe item name '" << inventory[0] << "' has ";
    cout << inventory[0].size() << " letters in it.\n";

    cout << "\nYou find  healing potion.\n";
    if (numItems < MAX_ITEMS) {
        inventory[numItems++] = "healing potion";
    }
    else {
        cout << "You have too many items and can't carry another.\n";
    }

    cout << "Your items:\n";
    for (int i = 0; i < numItems; ++i) {
      cout << inventory[i] << endl;
    }

    return 0;
}