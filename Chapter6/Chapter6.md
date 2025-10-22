# Chapter 6: References: Tic-Tac-Toe

## Examples

### [Referencing](./Examples/01_Referencing/referencing.cpp)

Introduces the concept of a `reference` in C++

### [Swap](./Examples/02_Swap/swap.cpp)

Demonstrate the use of references to alter argument variables

### [Inventory Displayer](./Examples/03_InventoryDisplayer/inventory_displayer.cpp)

Highlights the concept a `const reference` for constant read-only access

### [Inventory Referencer](./Examples/04_InventoryReferencer/inventory_referencer.cpp)

Demonstrates the ability to return a reference from a function

### [Major Project: Tic-Tac-Toe](./Examples/05_TicTacToe/tictactoe.cpp)

Shows the advantage of references in having multiple functions operate on a common state, through the well known game Hangman. Includes a non-trivial Computer opponent heuristic

## Exercises

### Discussion Questions

1. *What are the advantages and disadvantages of passing an argument by value?*
    - **Pro and Con:** Allows the value to be changed without modifying the original value
    - **Con**: Can result in excessive expensive copy operations for read-only values
    - **Pro**: Pass by value and return by value makes it clear when a value changes purely through the function signatures
2. *What are the advantages and disadvantages of passing a reference?*
    - **Pro**: Passing an alias in typically much cheaper than a copy
    - **Pro and Con**: Allows variables to have their value changed by a function
    - **Con**: Can make it unclear if and what variable values are changed
    - **Con**: Can't pass in a literal
3. *What are the advantages and disadvantages of passing a constant reference?*
    - **Pro**: Passing an alias is typically much cheaper than a copy
    - **Pro**: Makes it clear what values are changed through the return parameter, since the reference is read-only
    - **Pro**: Can pass a literal through a constant reference
    - **Con**: Can't change referenced values
4. *What are the advantages and disadvantages of returning a reference?*
    - **Pro**: Avoids expensive copy on return by value
    - **Con**: Reference can't be assigned to a variable, or this copy occurs regardless
    - **Con**: Can't return a local variable, since lifetime is only so long as the function exists
5. *Should game A.I cheat in order to create a more worthy opponent?*
    - This is an open question, typically players will verbally say that they don't like it when the A.I cheats or doesn't play by the same rules, however it can be very difficult to make a competitive A.I in an advanced technical game without some level of "cheating"

### Code Exercises

#### [Exercise 6.1](./Exercises/Ex6_1/mad_lib_references.cpp)

*Improve the Mad Lib game from Chapter 5 by using references to make the program more efficient*

Let us examine the program. In the case of the `askNumber` and `askText` program, the provided prompt is *read-only*, we simply print it out. We thus replace it with a `const` reference. However, we will *assign* their return values to a standard variable, so we leave the `return` as *return-by-value*

The remaining function is the `tellStory` function, here all the input parameters are *read-only* output passed to `cin` so we change all of the over to `const` references

#### [Exercise 6.2](./Exercises/Ex6_2/invalid_reference.cpp)

*What's wrong with the following program?*

```cpp
int main() {
    int score;
    score = 1000;
    float& rScore = score;
    return 0;
}
```

The reference `rScore` refers to a `float` but the type of `score` is `int`. References must preserve the type. This program should *fail to compile*, (see the linked code)

#### [Exercise 6.3](./Exercises/Ex6_3/local_reference.cpp)

*What's wrong with the following function?*

```cpp
int& plusThree(int number) {
    int threeMore = number + 3;
    return threeMore;
}
```

This function returns a reference to the local variable `threeMore`, the lifetime of this variable will expire when the function returns leaving the reference invalid. The linked implementation should generate a *compiler warning*

## Notes

## Summary

- A reference is an alias; it's another name for a variable
- You create a reference using `&`, the referencing operator
- A reference must be initialised when it's defined
- A reference can't be changed to refer to a different variable
- Whatever you do to a reference is done to the variable to which the reference refers
- When you assign a reference to a variable, you create a new copy of the referenced value
- When you pass a variable to a function by value, you pass a copy of the variable to a function
- When you pass a variable to a function by reference, you pass access to the variable
- Passing by reference can be more efficient than passing by value, especially when you are passing large objects
- Passing a reference provides direct access to the argument variable passed to a function. As a result, the function can make changes to the argument variable
- A constant reference can't be used to change the value to which it refers. You can declare a constant reference by using the keyword `const`
- You can't assign a constant reference or a constant value to a non-constant reference
- Passing a constant refrence to a function protects the argument variable from being changed by that function
- Changing the value of an argument variable passed to a function can lead to confusion, so game programmers consider passing a constant reference before passing a non-constant reference
- Returning a reference can be more efficient than returning a copy of a value, especially when you are returning large objects
- You can return a constant reference to an object so the object can't be changed through the returned reference
- A basic technique of game AI is to have the computer consider all of its legal moves and all of its opponent's legal replies before deciding which move to take next

## Questions and Answers

1. *Different programmers put the reference operator (`&`) in different places when declaring a reference. Where should I put it?*
    - Three basic styles exist with regard to the referencing operator. Some programmers opt for `int& ref == var;`, while others opt for `int & ref = var`;. Still others opt for `int &ref = var`;. The computer is fine with all three. There are cases to be made for each style; however, the most important thing is to be consistent
2. *Why can't I initialise a non-constant reference with a constant value?*
    - Because a non-constant reference allows you to change the value to which it refers
3. *If I initialise a constant reference with a non-constant variable, can I change the value of the variable?*
    - Not through the constant reference because when you declare a constant reference, you're saying that the reference can't be used to change the value to which it refers (even if that value can be changed by other means)
4. *How does passing a constant reference save overhead?*
    - When you pass a large object to a function by value, your program makes a copy of the object. This can be an expensive operation depending on the size of the object. Passing a reference is like only passing access to the large object; it is an inexpensive operation
5. *Can I make a reference to a reference?*
    - Not exactly. You can assign one reference to another reference, but the new reference will simply refer to the value to which the original reference refers
6. *What happens if I declare a reference without initialising it?*
    - Your compiler should complain because it's illegal
7. *Why should I avoid changing the value of a variable that I pass through a reference?*
    - Because it could lead to confusion. It's impossible to tell from only a function call whether a variable is being passed to change its value
8. *Does that mean I should always pass a constant reference?*
    - No. You can pass a non-constant reference to a function, but to most game programmers, this signal that you intend to change the argument variable's value
9. *If I don't change the argument variables passed to functions, how should I get new information back to the calling code?*
    - Use return values
10. *Can I pass a literal through a non-constant reference?*
    - No. If you try to pass a literal as a non-constant reference, you'll generate a compile error
11. *Is it impossible to pass a literal to a parameter that accepts a reference?*
    - No, you can pass a literal as a constant reference
12. *What happens when I return an object from a function?*
    - Normally, your program creates a copy of the object and returns that. This can be an expensivve operation, depending on the size of the object
13. *Why return a reference?*
    - It can be more efficient because returning a reference doesn't involve copying an object
14. *How can I lose the efficiency of returning a reference*
    - By assigning the returned reference to a variable. When you assign a reference to a variable, the computer must make a copy of the object to which the reference refers
15. *What's wrong with returning a reference to a local variable?*
    - The local variable doesn't exist once the function ends, which means that you're returning a reference to a non-existent object, which is illegal
