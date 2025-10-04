// Lost Fortune
// A personalised adventure

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    const int GOLD_PIECES = 900;
    int adventurers, killed, survivors;
    string leader;

    //get the information
    cout << "Welcome to Lost Fortune" << endl << endl;
    cout << "Please enter the following for your personalised adventure" << endl;

    cout << "Enter a number: ";
    cin >> adventurers;

    cout << "Enter a number, smaller than the first: ";
    cin >> killed;

    survivors = adventurers - killed;

    cout << "Enter your last name: ";
    cin >> leader;

    //tell the story
    cout << endl << "A brave group of " << adventurers << " set out on a quest ";
    cout << "- in search of the lost treasure of the Ancient Dwarves.";
    cout << " The group was led by that legendary rogue, " << leader << "." << endl;

    cout << endl << "Along the way, a band of maruading ogres ambushed the party.";
    cout << " All fought bravely under the command of " << leader;
    cout << ", and the ogres were defeated, but at a cost. ";
    cout << "Of the adventurers, " << killed << " were vanquished, ";
    cout << "leaving just " << survivors << " in the group." << endl;

    cout << "The party was about to give up all hope.";
    cout << " But while laying the deceased to rest, ";
    cout << "they stumbled upon the buried fortune. ";
    cout << "So the adventurers split " << GOLD_PIECES << " gold pieces. ";
    cout << leader << " held onto the extra " << (GOLD_PIECES % survivors);
    cout << " pieces to keep things fair of course" << endl;

    return 0;
}
