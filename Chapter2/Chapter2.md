# Chapter 2: Truth, Branching, and the Game Loop: Guess My Number

## Examples

### [Score Rater](./Examples/01_ScoreRater/)

Introduces the `if, else, else-if` construct

#### [Score Rater v1](./Examples/01_ScoreRater/v1/score_rater.cpp)

Demonstrate the `if` statement

#### [Score Rater v2](./Examples/01_ScoreRater/v2/score_rater.cpp)

Improves on the previous program with the `else` clause

#### [Score Rater v3](./Examples/01_ScoreRater/v3/score_rater.cpp)

Improves the previous programs through an `else-if` statement

### [Menu Chooser](./Examples/02_MenuChooser/menu_chooser.cpp)

Demonstrates the `switch` statement to perform a multi-way branch

### [Play Again](./Examples/03_PlayAgain/)

Introduces the `while` and `do-while` loop constructs

#### [Play Again v1](./Examples/03_PlayAgain/v1/play_again.cpp)

Demonstrates the `while` loop

#### [Play Again v2](./Examples/03_PlayAgain/v2/play_again.cpp)

Reimplements the previous program but with a `do-while` construct

### [Finicky Counter](./Examples/04_FinickyCounter/finicky_counter.cpp)

Demonstrates the use of `break` and `continue` to modify the behaviour of a loop

### [Designers Network](./Examples/05_DesignersNetwork/designers_network.cpp)

Uses a basic username and password chat room framework to demonstrate the use of logical `AND` (`&&`) and logical `OR` (`||`)

### [Major Project: Guess My Number](./Examples/07_GuessMyNumber/guess_my_number.cpp)

Ties together the concept of branching, looping and logical operators to write a simple program in which a human player has to guess
a computer generated number in as few guesses as possible

## Exercises

### Discussion Questions

1. *What kind of things would be difficult to program without loops?*
    - Any kind of functionality which has to repeat an arbitrary number of times is difficult without some form of loop construct.
2. *What are the advantages and disadvantages of the `switch` statement versus a series of `if` statements*
    - The switch statement has the advantage of performing the multiway with one comparison
    - The `if-else-if-else` construct requires us to write a sequentual series of `if-else-if` statements that must be tested in turn
    - Additionally the `switch` statement can use cascading behaviour
      - Code falls through from one case to the next in the absence of a `break`
      - Can write short code in cases where there is a standard behaviour with some preprocessing performed in a couple of special cases.
    - However the `if-else-if-else` construct is more flexible since the conditional for the branch may be any expression, not just an `int`
3. *When might you `omit` a break statement from the end of `switch` statement?*
    - As mentioned before, it may be that for a given operation we always want to perform some operation, however in a specific subset we want to perform some preprocessing
    - We can write a `default` case to capture the normal flow and then a special case using `switch` to preprocess but then have it fall through to the `default` behaviour
4. *When should you use a `while` loop over a `do` loop?*
    - When the loop may run $0$ or more times

### Code Exercises

#### [Exercise 2.1](./Exercises/Ex2_1/menu_chooser.cpp)

*Rewrite the Menu Chooser program from this chapter using an enumeration to represent difficulty levels. The variable `choice` will still be of type `int`*

We create the `enum difficulty` as

```cpp
    enum difficulty {EASY = 1, NORMAL, HARD}
```

We explicitly assign `EASY` the value of $1$ so all the constants are the same as in the original code. This implement is much better because now the numbers are assigned semantic meaning in the code through the enumeration. This also makes it easy to extend or modify the difficulty settings in the future

#### [Exercise 2.2](./Exercises/Ex2_2/ex2_2.cpp)

*What's wrong with the following loop?*

```cpp
int x = 0
while(x) {
    ++x;
    cout << x << endl;
}
```

At the first evaluation of the `while` condition `x` will have the vlaue $0$ which is equivalent to `false`. Hence the loop will never run (and if it did it would run endlessly since `x` will continously increase and the overflow behaviour of signed integers is undefined)

#### [Exercise 2.3](./Exercises/Ex2_3/guess_my_number.cpp)

*Write a new version of the [Guess My Number](#major-project-guess-my-number) program in which the player and the computer switch roles. That is, the player picks a number and the computer must guess what it is.*

This is pretty fun as a little exercise. For utility we convert the minimum and maximum allowed numbers to constants to give them semantic meaning and make them easy to change in the future.

For the player we now prompt the player to enter a number within the valid range, reprompting them if they give an invalid number.

For the computer, the simplest approach is to make the computer randomly guess a number until it's correct. However, like the human we want the computer to make use of the response **Too High!** or **Too Low!**. We could use an algorithm like [Binary Search](https://en.wikipedia.org/wiki/Binary_search) but that would be a bit boring. So lets keep the Computer a little bit random, we instead have the computer keep track of the *greatest* and *least* possible values as so:

- Let the range where the number lies be `[a, b]` and the computer guesses `c`
- If `c` is **Too High!** the valid range is now `[a, c - 1]` else if `c` is too low then the range is `[c + 1, b]`. Refer to this new range in either case as `[a', b']`.
- If `a' == b'`, then there is only one valid guess and we generate that number. Otherwise randomly generate a number in the range `[a', b']` and repeat.

## Notes

- To create interesting programs you need to ability to execute (or skip) sections of code based on some condition

### Understanding Truth

- Truth can be represented with `true` and `false`
- Truthfulness can be stored in a `bool`
  - e.g. `bool fact = true, fiction = false`
- Any expression can be evaluated for truthfulness
  - Any non-zero value is `true`
  - Zero is interpreted as `false`
- A common truthfulness expression is a *relation*

| Operator | Meaning                  | Sample Expression | Evaluates to |
|----------|--------------------------|-------------------|--------------|
| ==       | equal to                 | 5 == 5, 5 == 8     | true, false   |
| !=       | not equal to             | 5 != 8, 5 != 5     | true, false   |
| >        | greater than             | 8 > 5, 5 > 8       | true, false   |
| <        | less than                | 5 < 8, 8 < 5       | true, false   |
| >=       | greater than or equal to | 8 >= 5, 5 >= 8     | true, false   |
| <=       | less than or equal to    | 5 <= 8, 8 <= 5     | true, false   |

### Using the `if` Statement

- `if` statements allow you to test an expression for truthfulness and conditionally execute some code

```cpp
if (expression) {
    statement;
}
```

- If `expression` is `true`, then `statement` is executed.
- Otherwise statement is skipped

### Example [Score Rater](#score-rater-v1)

### Testing `true` and `false`

>[!CAUTION]
>Notice that you don't use a semicolon after the closing parenthesis of the expression you test in an `if` statement. If you were to do this, you'd create an empty statement that would be paired with the `if` statement, essentially rendering the `if` statement useless. Here's an example
>
>```cpp
>if (false);
>{
>   cout << "Thhis is never displayed.\n\n";    
>}
>```
>
>By adding the semicolon after (`false`), I create an empty statement thats associated with the `if` statement. The preceding code is equivalent to:
>
>```cpp
>if (false) {
>   ; // an empty statement which does nothing    
>}
>{
>   cout << "This is never displayed.\n\n";    
>}
>```
>
> The `if` statement sees the `false` value and skips the next statement (the empty statement). Then the program goes on its merry way to the statement after the `if` statement, which displays the message, `"This is never displayed"`.
>
>Be on guard for this error. It's an easy one to make and because it's not illegal, it won't produce a compile error

### Interpreting a Value as `true` or `false`

- As mentioned any expression can be evaluated as `true` (non-zero) or `false`

### Using Relational Operators

>[!CAUTION]
>The equal to relational operator is `==`. Don't confuse it with the assignment operator `=`.
>
>It's not illegal to use the assignment operator instead of the equal to relational operator, the results might not be what is expected though. Look at this code
>
>```cpp
>int score = 500;
>if (score = 1000) {
>   cout << " You scored 1000 or more. Impressive!\n";    
>}
>```
>
> As a result of this code, `score` is set to `1000` and the message, `"You scored 1000 or more. Impressive!"` is displayed. Here's what happens: `score` is $500$ before the `if` statement. When the expression is evaluated, `score` is assigned the value $1000$, the assignment expression is evaluated as $1000$ which is non-zero and interpreted as `true`. As a result the string is displayed.
>
>Be on guard for this type of mistake. It's easy to make and in some cases can be hard to find (though most modern compilers should warn about it.)

### Nesting `if` statements

## Summary

- You can use the truthfulness of an expression to branch (or skip) code
- You can represent truthfulness with the keywords `true` and `false`
- You can evaluate any value or expression for truthfulness
- Any non-zero value evaluates to `true`, while zero evaluates to `false`
- A common way to create an expression to be evaluated as `true` or `false` is to compare values with the *relational operators*
- The `if` statement tests an expression and executes a section of code only if the expression is `true`
- The `else` caluse of an `if` statement specifies code that should be executed only if the expression tested in the `if` statement is `false`
- The `switch` statement tests a value that can be treated as an `int` and executes a section of code labeled with the corresponding value
- The `default` keyword, when used in a `switch` statement, specifies code to be executed if the value tested in the `switch` statemetn matches no listed values
- The `while` loop executes a section of code if an expression is `true` and repeats the code as long as the expression is `true`
- A `do` loop executes a section of code and then repeats the code as long as the expression is `true`
- Used in a loop, the `break` statement immediately ends the loop
- Used in a loop, the `continue` statement immediately causes the control of the program to branch to the top of the loop
- The `&&` (AND) operator combines two smaller expressions to create a new expression that is `true` only if both simpler expressions are `true`
- The `||` (OR) operator combines two simpler expressions to create a new expression that is `true` if either simpler expression is `true`
- The `!` (NOT) operator creates a new expression that is the opposite truth value of the original
- The game loop is a generalised representation of the flow of events in a game, the core of which repeats
- The file `cstdlib` contains functions that deal with generating random numbers
- The function `srand()`, defined in `cstdlib`, seeds the random number generator
- The function `rand()`, defined in `cstdlib`, returns a random number.

## Questions and Answers

1. Do you have to use the keywords `true` and `false`?
    - No, but its a good idea since they have clear semanatic meaning
2. Can you assign a `bool` variabe something other than `true` or `false`?
    - Yes, you can assign an expression to a bool variable, which will store the truthfulness of the result
3. Can you use a `switch` statement to test some non-integer value?
    - No, `switch` statements only work with values that can be interpreted as integers
4. How can you test a single non-integer value against multiple values if you can't use a `switch` statement?
    - Use an `if-else-if-else` construct
5. What's a infinite loop?
    - A loop that never ends regardless of input or state
6. Why are infinite loops considered bad?
    - A program stuck in an infinite loop will typically never end on its own. It may have to be shut down by the operating system, or the computer itself may need to be rebooted
7. Won't a compiler catch an infinite loop and flag it as an error?
    - No, an infinite loop is a logical error - the kind of error a programmer makes.
    - *Some modern compilers may have a limited ability to detect an infinite loop*
8. If infinite loops are a bad thing,then isn't a `while(true)` loop a bad thing?
    - No, when a programmer creates a `while(true)` loop, they should provide a way for the loop to end (usually through a `break` statement)
9. Why would a programmer create a `while(true)` loop?
    - They are typically used for the main loop of a program such as the game loop
10. Why do some people feel that using a `break` statement to exit a loop is poor programming?
    - Because indiscriminate use of `break` statements can make it hard to understand and reason about the conditions under which a loop ends. However, sometimes the use of a `while(true)` loop along with a `break` statement can be clearer than creating the same loop in a more traditional way
11. What's a pseudorandom number?
    - A random number that's usually generated by a formula. As a result, a series of pseudorandom numbers is not truely random, but good enough for most purposes
12. What's seeding a random number generator?
    - It's giving the random number generator a seed, such as an integer, which affects the way the generator produces random numbers. If you don't seed a random number generator, it will produce the same series of numbers each time its run from the beginning of a program
13. Don't you always want to seed the random number generator before using it?
    - No nessecarily. You might want a program to produce the exact same sequence of "random" numbers each time it runs for testing purposes, for example
14. How can I generate more truely random numbers?
    - There are third-party libraries that produce better psuedorandom numbres than the ones that typically come with C++ compilers
15. Do all games use the game loop?
    - The game loop is just a way of looking at a typical game's flow of events. Just because this paradigm fits a particular game does not mean that game is implemented with a loop around the bulk of its code