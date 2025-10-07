# Chapter 1: Types, Variables and Standard I/O: Lost Fortune

## Examples

### [Game Over](./Examples/01_GameOver/)

A play on the classic hello world.

#### [Game Over v1](./Examples/01_GameOver/v1/game_over.cpp)

Prints `Game Over!`.

#### [Game Over v2](./Examples/01_GameOver/v2/game_over.cpp)

Same as the previous program but using global import of the `std` namespace.

#### [Game Over v3](./Examples/01_GameOver/v3/game_over.cpp)

Same as the previous program but using specific import of only `std::cout`, and `std::endl`.

### [Expensive Calculator](./Examples/02_ExpensiveCalculator/expensive_calculator.cpp)

Demonstrates basic arithmetic operations with C++.

### [Game Stats](./Examples/03_GameStats/)

Demonstrates variables and constants.

#### [Game Stats v1](./Examples/03_GameStats/v1/game_stats.cpp)

Introduces variables and types as well as reading a value from standard input with `cin`.

#### [Game Stats v2](./Examples/03_GameStats/v2/game_stats.cpp)

Demonstrates arithmetic operations on variables.

#### [Game Stats v3](./Examples/03_GameStats/v3/game_stats.cpp)

Introduces constants

### [Major Project: Lost Fortune](./Examples/04_LostFortune/lost_fortune.cpp)

Ties together the concepts of variables and I/O through a simple interactive text-based story.

## Exercises

### Discussion Questions

1. *How does having a widely adopted C++ Standard help game programmers?*
    - A standard language allows for a common ecosystem to be built up.
    - People can share code and tooling ecosystems.
    - People can move between roles without the need to learn a whole new set of rules.
2. *What are the advantages and disadvantages of employing the `using` directive?* 
    - Reduces the amount of code that has be written when accessing namespaced items
    - Increases the risk of collision between similarly named objects.
    - Makes it harder to tell where functions originate from.
3. *Why might you define a new name for an existing type?*
    - Type names are often overwritten to provide **semantic** meaning e.g. a **length** and a **size** might both be `unsigned ints` but they are semantically different types.
4. *Why are there two versions of the increment operator?*
    - `++x` increments `x` and returns the value of `x` **after** the increment
    - `x++` increments `x` and returns the value of `x` **before** the increment.
    - Often one specific behaviour is desirable for compact code, **e.g.** the common stack idiom:

    ```C
    int pop() {
        return stack[--head];
    }
    void push(val) {
        stack[head++] = val;
    }
    ```

Here `head` points to the next free index on the stack, so the `pop` moves the head down to the previous occupied index and returns it, while the `push` increments the `head` and places the pushed value where `head` used to be.

### Code Exercises

#### Exercise 1.1

*Create a list of six legal variable names, three good and three bad choices. Explain why each is good or bad.*

| Variable Name                              | Good or Bad? | Why?                                                                                            |
|--------------------------------------------|--------------|-------------------------------------------------------------------------------------------------|
| `a`                                          | Bad          | short, nondescript                                                                              |
| `ThisVariableStoresNumbersFromOneThroughTen` | Bad          | too long and does not describe what the variable represents                                     |
| `InvSqrRoot`                                 | Bad          | Too abreviated InverseSquareRoot almost as long and more descriptive                            |
| `i`                                          | good         | short, but accepted as a universal mathematical index value (only use for short counting loops) |
| `length`                                     | good         | short and descriptive                                                                           |
| `is_legal_move`                              | good         | nonabreviated, describes what the variable represents                                           |

#### [Exercise 1.2](./Exercises/Ex1_2/seven_divided_by_three.cpp)

What's displayed by each line in the following code snippet? Explain each result.

```C
cout << "Seven divided by three is " << 7 / 3 << endl;
cout << "Seven divided by three is " << 7.0 / 3 << endl;
cout << "Seven divided by three is " << 7.0 / 3.0 << endl;
```

The display is

```text
Seven divided by three is 2
Seven divided by three is 2.33333
Seven divided by three is 2.33333
```

- In the first line we have integer division so the result is truncated.
- In the second an integer divides a float, so the whole expression is treated as floating point division.
- In the final line both numbers are floats and so floating point division takes place.

#### [Exercise 1.3](./Exercises/Ex1_3/game_scores.cpp)

*Write a program that gets three game scores from a user and displays the average.*

This is simple, we read the three integers in from standard input and then divide by the floating point value `3.0`. This is to avoid integer truncation, we also make the number of scores a *constant* in case we wanted to change this program in the future to support taking the average of a different number of scores.
