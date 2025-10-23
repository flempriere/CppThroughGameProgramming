// TicTacToe 2.0
// Replaces the use of references with pointers

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

//function prototypes
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(vector<char> const* const board);
char winner(vector<char> const* const board);
bool isLegal(vector<char> const* const board, int move);
int humanMove(vector<char> const* const board);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

// main function
int main() {
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);

    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = 'X';
    displayBoard(&board);

    while(winner(&board) == NO_ONE) {
        if (turn == human) {
            move = humanMove(&board);
            board[move] = human;
        }
        else {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(&board);
        turn = opponent(turn);
    }
    announceWinner(winner(&board), computer, human);
    return 0;
}

void instructions() {
    cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe\n";
    cout << "--where human brain is piit against silicon processor\n\n";

    cout << "Make your move known by entering a number, 0-8. The number\n";
    cout << "corresponds to the desired board position, as illustrated:\n\n";

    cout << "       0 | 1 | 2\n";
    cout << "       ---------\n";
    cout << "       3 | 4 | 5\n";
    cout << "       ---------\n";
    cout << "       6 | 7 | 8\n";
    cout << "       ---------\n\n";

    cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

char askYesNo(string question) {
    char response;
    do {
        cout << question << "(y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}

int askNumber(string question, int high, int low) {
    int number;
    do {
        cout << question << " (" << low << " - " << high << " ): ";
        cin >> number;
    } while(number > high || number < low);

    return number;
}

char humanPiece() {
    char go_first = askYesNo("Do you require the first move?");
    if (go_first == 'y') {
        cout << "\nThen take the first move. You will need it.\n";
        return X; 
    }
    else {
        cout << "\nYour bravery will be your undoing... I will go first.\n";
        return O;
    }
}

char opponent(char piece) {
    if (piece == X) {
        return O;
    }
    else {
        return X;
    }
}

void displayBoard(vector<char> const* const board) {
  cout << "\n\t" << (*board)[0] << " | " << (*board)[1] << " | " << (*board)[2];
  cout << "\n\t" << "---------";
  cout << "\n\t" << (*board)[3] << " | " << (*board)[4] << " | " << (*board)[5];
  cout << "\n\t" << "---------";
  cout << "\n\t" << (*board)[6] << " | " << (*board)[7] << " | " << (*board)[8];
  cout << "\n\n";
}

char winner(vector<char> const* const board) {
    // all possible winning rows
    const int TOTAL_ROWS = 8;
    const int WINNING_ROWS[TOTAL_ROWS][3] = { {0,1,2},
                                            {3, 4, 5},
                                            {6, 7, 8},
                                            {0, 3, 6}, 
                                            {1, 4, 7}, 
                                            {2, 5, 8},
                                            {0, 4, 8}, 
                                            {2, 4, 6}};

    // if any winning row has three values that are the same (and non-empty)
    // then we have a winner

    for (int row = 0; row < TOTAL_ROWS; ++row) {
        if (((*board)[WINNING_ROWS[row][0]]) != EMPTY &&
            ((*board)[WINNING_ROWS[row][0]] == (*board)[WINNING_ROWS[row][1]]) &&
            ((*board)[WINNING_ROWS[row][1]]) == (*board)[WINNING_ROWS[row][2]]) {
                return (*board)[WINNING_ROWS[row][0]];
            }
    }

    // since nobody has won, check for a tie (no empty squares left)
    if (count(board->begin(), board->end(), EMPTY) == 0) {
        return TIE;
    }
    //since nobody won and not a tie, game continues
    return NO_ONE;
}

inline bool isLegal(vector<char> const* const board, int move) {
    return ((*board)[move] == EMPTY);
}

int humanMove(vector<char> const* const board) {
    int move = askNumber("Where will you move?", board->size() - 1);
    while(!isLegal(board, move)) {
        cout << "\nThat square is already occupied, foolish human.\n";
        move = askNumber("Where will you move?", board->size() - 1);
    }
    cout << "Fine...\n";
    return move;
}

int computerMove(vector<char> board, char computer) {
    unsigned int move = 0;
    bool found = false;
    //if computer has a winning move, then computer makes that move
    while(!found && move < board.size()) {
        if (isLegal(&board, move)) {
            board[move] = computer;
            found = winner(&board) == computer;
            board[move] = EMPTY;
        }

        if (!found) {
            ++move;
        }
    }
    //otherwise, if human can win on nexxt move, tahts the move to make
    if (!found) {
        move = 0;
        char human = opponent(computer);

        while (!found && move < board.size()) {
            if (isLegal(&board, move)) {
                board[move] = human;
                found = winner(&board) == human;
                board[move] = EMPTY;
            }
            
            if (!found) {
                ++move;
            }
        }
    }

    //otherwise, moving to the best open square is the move to make
    if (!found) {
        move = 0;
        unsigned int i = 0;
        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        //pick best open square
        while (!found && i < board.size()) {
            move = BEST_MOVES[i];
            if (isLegal(&board, move)) {
                found = true;
            }
            ++i;
        }
    }
    cout << "I shall take square number " << move << endl;
    return move;
}

void announceWinner(char winner, char computer, char human) {
    if (winner == computer) {
        cout << winner << "'s won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }
    else if (winner == human) {
        cout << winner << "'s won!\n";
        cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
        cout << "But never again! I the computer, so swear it!\n";
    }

    else {
        cout << "It's a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate... for tis the best you will ever achieve.\n";
    }
}