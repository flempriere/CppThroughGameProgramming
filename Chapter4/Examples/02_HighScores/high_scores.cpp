// High Scores
// Demonstrates algorithms

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

//Headers below replaced with the random header above
//#include <ctime>
//#include <cstdlib>


using namespace std;

int main() {
    vector<int>::const_iterator iter;

    cout << "Creating a list of scores.";
    vector<int> scores;
    scores.push_back(1500);
    scores.push_back(3500);
    scores.push_back(7500);

    cout << "\nHigh Scores:\n";
    for (iter = scores.begin(); iter != scores.end(); ++iter) {
        cout << *iter << endl;
    }

    cout << "\nFinding a score.";
    int score;
    cout << "\nEnter a score to find: ";
    cin >> score;
    iter = find(scores.begin(), scores.end(), score);
    if (iter != scores.end()) {
        cout << "Score found.\n";
    }
    else {
        cout << "Score not found.\n";
    }

    cout << "\nRandomising Scores.";

    // The original code below, uses random_shuffle, which is deprecated, from
    // C++17 The new suggested function is shuffle in conjunction with a random
    // number generator from the random header.
    //
    // srand(static_cast<unsigned int>(time(0)));
    // random_shuffle(scores.begin(), scores.end());

    // Code adjusted to use the new methodology
    // See this reddit discussion:
    // https://www.reddit.com/r/cpp_questions/comments/kbothg/with_random_shuffle_deprecated_what_function/


    random_device rd;
    mt19937 rng(rd());
    shuffle(scores.begin(), scores.end(), rng);
    cout << "\nHigh Scores:\n";
    for (iter = scores.begin(); iter != scores.end(); ++iter) {
        cout << *iter << endl;
    }

    cout << "\nSorting scores.";
    sort(scores.begin(), scores.end());
    cout << "\nHigh Scores:\n";
    for (iter = scores.begin(); iter != scores.end(); ++iter) {
      cout << *iter << endl;
    }

    return 0;
}