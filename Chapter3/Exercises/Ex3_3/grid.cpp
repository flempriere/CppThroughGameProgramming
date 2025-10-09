// Exercise 3.3
// What's wrong with the following code?
// {
//     const int ROWS = 2;
//     const int COLUMNS = 3;
//     char board[COLUMNS][ROWS] = {{'O', 'X', 'O'}, {' ', 'X', 'X'}};
// }
// COLUMNS and ROWS have been flipped, so board is actually 3 x 2 rather than 2 x 3
// This code should fail to compile


int main() {
    const int ROWS = 2;
    const int COLUMNS = 3;
    char board[COLUMNS][ROWS] = {{'0', 'X', 'O'}, {' ', 'X', 'X'}};
    return 0;
}