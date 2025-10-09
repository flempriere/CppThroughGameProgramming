# Chapter3: For Loops, String and Arrays: Word Jumble

## Examples

### [Counter](./Examples/01_Counter/counter.cpp)

A simple counter demonstrating `for` loops

### [String Tester](./Examples/02_StringTester/string_tester.cpp)

Demonstrates the behaviour of `string` objects and common operations

### [Hero's Inventory](./Examples/03_HerosInventory/)

Introduces the concept of arrays

#### [Hero's Inventory 1.0](./Examples/03_HerosInventory/v1/heros_inventory.cpp)

Demonstrates the use of an array to store multiple values under the same "variable".

#### [Hero's Inventory 2.0](./Examples/03_HerosInventory/v2/heros_inventory.cpp)

Demonstrates the use of an initiliser list to create an array

### [Tic-Tac-Toe](./Examples/04_TicTacToe/tictactoe.cpp)

Demonstrates the use of multidimensional arrays by printing a sample tic-tac-toe board state

### [Major Project: Word Jumble](./Examples/05_WordJumble/word_jumble.cpp)

Ties together `for` loops, `strings` and `arrays` in the game *Word Jumble* were the player is given a randomly jumbled word from an internally stored dictionary and asked to guess the jumbled word

## Exercises

### Discussion Questions

1. *What are some of the things from your favourite game that you could represent as objects? What might their data members and member functions be?*
    - Consider the game chess, we could consider two objects
        1. A game board, which stores the game state and where pieces are as data members, and has functions to update the board
        2. Pieces which may store their location, points value and have functions that can be used to calculate their valid moves
2. *What are the advantage of using an array over a group of individual variables?*
    - Common variables are grouped together in the program under one semantic label and in the memory as one block
    - It is easier to adjust the number of elements by changing the size of the array as opposed to creating or deleted variable names
    - We can easily write code to perform algorithms on arbitrarily-sized arrays, we can't easily do this for an arbitrary collection of independently named variables
3. *What are some limitations imposed by a fixed array size?*
    - Fixes the amount of memory used regardless of if this is *too large* or *too small*
    - Can't add more elements to the array that the fixed size allows

### Code Exercises

#### [Exercise 3.1](./Exercises/Ex3_1/word_jumble.cpp)

*Improve the Word Jumble game by adding a scoring system. Make the point value for a word based on its length. Deduct points if the player asks for a hint*

We implement a simple score situation were the score for a word is set as equal to the length of that word. Then after an incorrect guess the score is reduced by $1$ (to a minimum of $0$.) If the player asks for a hint, their remaining score is halved.

#### [Exercise 3.2](./Exercises/Ex3_2/phrase.cpp)

*What is wrong with the following code?*

```cpp
for (int i = 0; i <= phrase.size(); ++i) {
    cout << "Character at position " << i << " is: " << phrase[i] << endl;
}
```

strings store their characters in an underlying array of characters. For a string containing $`n`$ characters these are in the indices $0 \ldots n - 1$. Typically the $n$-th index then stores a character called a *null terminator*, which is not part of the actual string itself but is designed to demarcate the end of the string. By running over all the indices up to and including *size* above, we accidently print out this null terminator

#### [Exercise 3.3](./Exercises/Ex3_3/grid.cpp)

*What's wrong with the following code?*

```cpp
{
    const int ROWS = 2;
    const int COLUMNS = 3;
    char board[COLUMNS][ROWS] = {{'O', 'X', 'O'}, {' ', 'X', 'X'}};
}
```

The problem above is that the way the code semantically reads is that board should be a $2 \times 3$ array, but instead the columns and rows have been flipped as so what is actually happening is board is declared as a $3 \times 2$, which we then try to initialise as a $2 \times 3$ array. This code should cause a *compile error*

## Notes

## Summary

- The `for` loop lets you repeat a section of code. In a `for` loop, you can provide an initialisation statement, an expression to test, and an action to take after each loop iteration
- `for` loops are often used for counting or looping through a sequence
- Objects are encapsulated, cohesive entitites that combine data (called *data members*) and functions (called *members functions*)
- `string` objects (often called just *strings*) are defined in the file `string`, which is part of the standard library. `string` objects allow you to store a sequence of characters and also have member functions
- `string` objects are defined so they work intuitively with familiar operators, such as the concatenation operator and the relational operators
- All `string` objects have member functions, including those for determining a `string` object's length, determining whether or not a `string` object is empty, finding substrings and removing substrings
- Arrays provide a way to store and access sequences of any type
- A limitation of arrays is they have a fixed length
- You can access individual elements of `string` objects and arrays through the subscripting operator
- Bounds checking is not enforced when attempts are made to access individual elements of `string` objects or arrays. Therefore, bounds checking is up to the programmer
- C-style strings are character arrays terminated with the null character. They are the standard way to represent strings in the C language. Even though C-style strings are perfectly legal in C++, `string` objects are the preferred way to work with sequence of characters

## Questions and Answers

1. Which is better, a `while` loop or a `for` loop
    - Neither is inherently better than the other. Use the loop that best fits the usecase
2. When might it be better to use a `for` loop than a `while` loop?
    - You can create a `while` loop to do the job of any `for` loop; however, there are some cases were a `for` loop is more compact. Those include counting and iterating through a sequence
3. Can I use `break` and `continue` statements with `for` loops?
    - Sure. They behave just they do in `while` loops: `break` ends the loop and `continue` jumps control back to the top
4. Why do programmers tend to use variablee names such as `i`, `j` and `k` as counters in `for` loops?
    - Largely out of tradition, and some legacy convention around variable naming in the language `FORTRAN` which itself was inspired by mathematical notation where `i`, `j`, `k` are common index variables
5. I dont have to include a file to use `int` or `char` types, so why do I have to include the `string` file to use strings?
    - `int` and `char` are built-in types. They can be accessed in any C++ program. The `string` type, on the other hand, is not a built-in type. It;s defined as part of the standard library in the `string` file.
6. How did C-style strings get their name?
    - In the C programming language, programmers represent strings using character arrays terminated by a null character. The practice was carried forward into C++. After the `string` type was introduced, C-style strings became terminology to refer to the old style of strings
7. Why should I use `string` objects over C-style strings?
    - `string` objects are significantly more programmer friendly. They are dynamically sizeable meaning they can be created without specifying the a fixed size. Additionally not having to manage the null character makes manipulating them much easier to reason about
8. Should I ever use C-style strings?
    - You should opt to use `string` objects whenever possible. If you're working on an existing program that uses C-style strings, the you might have to work with them
9. What is operator overloading?
    - A process that allows you to define the use of familiar operators (like $+$ and $-$) in different contexts with different but predictable results. For example $+$ is overloaded by the `string` type to perform concatenation since numerical addition doesn't exist for strings.
10. Can't operator overloading be confusing?
    - It can be. Overloading assigns a new meaning to an operator, but the new meaning is fixed to a specfic context. E.g. it should be clear that `4 + 6` and `string1 + string2` are doing two different types of *addition* operations.
11. Can I use the `+=` operator to concatenate `strings`?
    - Yes, the `+=` operator is concatenated to work as you would expect
12. To get the number of characters in a `string` object should I use the `length()` member function or the `size()` member function?
    - Both return the same value, so you can use either
13. What's a predicate function?
    - A function that returns either `true` or `false`. The string object member function `empty()` is an example of a predicate function
14. What happens if I try to assign a value to an element beyond the bounds of an array?
    - C++ will allow you to make the assignment. However the results are unpredictable and might cause your program to crash. That's because you altering some unknown part of the computer's memory
15. Why should I use multidimensional arrays?
    - To make working with a group of elements more intuitive. For example a chess board can be represented in one dimension as an array `chessBoard[64]` or you could represent it with a more intuitive, two-dimensional array, as in `chessBoard[8][8]`
