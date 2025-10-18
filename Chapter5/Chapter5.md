# Chapter 5: Functions: Mad Lib

## Examples

### [Instructions](./Examples/01_Instructions/instructions.cpp)

Illustrates how to write a function

### [Yes or No](./Examples/02_YesOrNo/yes_or_no.cpp)

Demonstrates the use of function parameters and introduces return values

### [Scoping](./Examples/03_Scoping/scoping.cpp)

Demonstrates variable scopes

### [Global Reach](./Examples/04_GlobalReach/global_reach.cpp)

Introduces the concept of global variables

### [Give me a Number](./Examples/05_GiveMeANumber/give_me_a_number.cpp)

Demonstrates the idea of default arguments for function parameters

### [Triple](./Examples/06_Triple/triple.cpp)

Shows how to *overload* functions

### [Taking Damage](./Examples/07_TakingDamage/taking_damage.cpp)

Illustrates the use of *function inlining* as a performance optimisation

### [Major Project: Mad Lib](./Examples/08_MadLib/mad_lib.cpp)

Demonstrates how to break a program down into into components using well-designed function calls through a simple Mad Lib game in which a player provides a number of words to complete a story

## Exercises

### Discussion Questions

1. *How does function encapsulation help you write better programs?*
    - It hides the implementation of independent components from each other, which reduces coupling and promotes code reuse and helps with maintainability
2. *How can global variables make code confusing?*
    - They create dependencies between disconnected parts of the code when different functions all read or modify the variables. They can also be hard to analyse since they are declared in a different part of the code to where they are used
3. *How can global constants make code clearer?*
    - They allow the program to provide semantic meaning to a commonly used constant, removing instances of *magic numbers*. This also means if the constant is changed it can be done in one part of the code, rather than everywhere the constant is used
4. *What are the pros and cons of optimising code?*
    - *Pro*: Optimised code runs more efficiently and faster providing a better user experience.
    - *Pro*: Optimised code tends to be more *scalable*
    - *Con*: Often takes an increased amount of developer time to implement, early optimisation can waste a lot of time!
    - *Con*: Optimised code is often more difficult to understand than a straightforward implementation and so can be harder to maintain
5. *How can software reuse benefit the game industry?*
    - It increases productivity by allowing developers to focus on novel or new aspects of a game
    - It allows people to transfer between projects faster when there is a common set of features

### Code Exercises

#### [Exercise 5.1](./Exercises/Ex5_1/broken_function.cpp)

*What's wrong with the following prototype?*

```cpp
int askNumber(int low = 1, int high);
```

Parameters without default arguments must come before those with default arguments. The reasoning why should be clear, suppose we called the above function as `askNumber(5)`, reading the function left to right we would expect the $5$ to be referring to `low` which means we're missing the required argument to `high`, the other reading is that this is called  as `askNumber(1, 5)`.

The attached code demonstrates this, you should see that the code fails to compile.

#### [Exercise 5.2](./Exercises/Ex5_2/hangman.cpp)

*Rewrite the Hangman game from Chapter 4 using functions. Include a function to get the player's guess and another function to determine whether the player's guess is in the secret word*

Looking at the original hangman we can view the game loop as containing several independent states as,

```text
load possible words and select one
*perform some setup*
while(word not guessed AND not hanged)
    display the current game state
    get the player's guess
    check if the guess is in the word 
        update the guessed word if the guess is in it
    otherwise
        increment wrong guesses
print some information about the end of the game
```

We can see that a number of these form independent operations where there is effectively *one* thing being done. We want to rewrite these as functions, we get the first function

```cpp
string createWord()
```

which takes no arguments, and is responsible for building the word dictionary (*in this case from a `vector`*), shuffling it, and returning the top card, it's implementation is

```cpp
string createWord() {
    vector<string>words;
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    random_device rd;
    mt19937 rng(rd());
    shuffle(words.begin(), words.end(), &rng);

    return words[0];
}
```

which is basically just extracted from the original implementation.

The next function is to display the current game state, for this we need to know how many `wrong` guesses we've made, the `string` of letters `used` so far, and the `string` containing the state of the guessed word so far. The signature is then

```cpp
void displayGameState(int wrong, string used, string soFar);
```

Which is then implemented as,

```cpp
void displayGameState(int wrong, string used, string soFar) {
    cout << "\n\nYou have " << MAX_WRONG - wrong;
    cout << " guesses left.\n";
    cout << "\nYou've used the following letters:\n" << used << endl;
    cout << "\nSo far, the word:\n" << soFar << endl;
}
```

We then get the player's guess, for this we need to know what letters we've guessed, so that we can ensure the player guesses a new letter. The prototype is then

```cpp
char getGuess(string used);
```

and implemented as,

```cpp
char getGuess(string used) {
    char guess;
    cout << "\n\nEnter your guess: ";
    cin >> guess;
    guess = toupper(guess); // make uppercase since secret word is uppercase
    while (used.find((guess)) != string::npos) {
        cout << "\nYou've already guessed " << guess << endl;
        cout << "Enter your guess: ";
        cin >> guess;
        guess = toupper(guess);
    }
    return guess;
}
```

We then implement a `bool` helper function to return if the guess is the word, this requires the `guess` and the `word`, with the prototype

```cpp
bool guessIsInWord(char guess, string word);
```

and a simple implementation

```cpp
bool guessIsInWord(char guess, string word) {
    return word.find(guess) != string::npos;
}
```

which simply wraps the `find` method on `word`.

The last function we implement is one to handle updating the state of the guessed word, this requires the guess, the current state, and the word itself. So has signature,

```cpp
string updateWordSoFar(char guess, string word, string soFar) {
}
```

and has the implementation,

```cpp
string updateWordSoFar(char guess, string word, string soFar) {
    for (unsigned int i = 0; i < word.length(); ++i) {
        if (word[i] == guess) {
        soFar[i] = guess;
        }
    }
    return soFar;
}
```

#### [Exercise 5.3](./Exercises/Ex5_3)

*Using default arguments, write a function that asks the user for a number and returns that number. The function should accept a string prompt from the calling code. If the caller doesn't supply a string for the prompt the functionn should use a generic prompt. Next, using function overloading, write a function that acheives the same result.*

The function prototype is implemented as

```cpp
int getNumber(string prompt = "Enter a Number: ");
```

This makes the default argument to prompt `"Enter a Number: "`. The implementation is then,

```cpp
int getNumber(string prompt) {
    int number;
    cout << prompt;
    cin >> number;
    return number;
}
```

If we want to reimplement this using function overloading we have two functions, one with a `prompt` argument, and one without, i.e.

```cpp
int getNumber(string prompt);
int getNumber();
```

and the implementations become,

```cpp
int getNumber(string prompt) {
    int number;
    cout << prompt;
    cin >> number;
    return number;
}
```

and

```cpp
int getNumber() {
    int number;
    cout << "Enter a Number: ";
    cin >> number;
    return number;
}
```

Which version is better, is probably up to the individual in this case. Observe in the former case we have *one* function prototype and definition as opposed to *two*, but the two seperate functions arguably make the default arguments clearer by putting them in the context of their use. However, imagine if we had two or more default arguments! Then the number of overloaded cases we would have to write would start to explode

## Notes

- Functions allow you break big programs into smaller, bite-sized chunks of code

### Creating Functions

- C++ like most languages let you declare new functions

### Example [Instructions](#instructions)

### Declaring Functions

- Before being used, functions must be declared
- *function prototypes* is a common way to do this

The general structure is,

```cpp
return-type function-name(param-type param-name, ...);
```

If the function does not return *anything* then we use the `void` return type

- A function definition can also act as it's declaration
  - This requires the function to be declared before any calls to it

>[!TIP]
>Although you don't have to use prototypes, they offer a lot of benefits, not the least of which is making your code clearer

### Defining Functions

- A function is defined similar to its prototype, but with the function body providing an *implementation* of the function, e.g.

```cpp
return-type name(param-type param-name, ...) {
    function-body
}
```

## Summary

- Functions allow you to break up your programs in manageable chunks
- One way to declare a function is to write a function prototype (code that lists the return value, name, and parameter types of a function)
- Defining a function means writing all the code that makes the function tick
- You can use the `return` statement to return a value from a function. You can also use `return` to end a functiion that has `void` as its return type
- A variable's scope determines where the variable can be seen in your program
- Global varibales are accessible from any part of your program. In general, you should try to limit your use of global variables
- Global constants are accessible from any part of your program. Using global constants can make your program code clearer
- Default arguments are assigned to a parameter if no value for the parameter is specified in the function call
- Function overloading is the process of creating multiple definitions for the same function, each of which has a different set of parameters
- Function inlining is the process of askign the compiler to inline a function; meaning the compiler should make a copy of the function everywhere in the code where the function is called. Inlining very small functions can sometimes yield a performance boost

## Questions and Answers

1. *Why should I write a function?*
    - Functions allow you to break up your programs into logical pieces. These pieces result in smaller, more manageable chunks of code, which are easier to work with than a single monolithic program
2. *What's encapsulation?*
    - At its core, encapsulation is about keepign things seperate. Function encapsulation provides that variables decalred in a function are not accessible outside the function, for example
3. *What's the difference between an argument and a parameter?*
    - An argument is what you use in a function call to pass a value to a function. A parameter is what you use in a function definition to accept values passed to a function
4. *Can I have more than one `return` statement in a function?*
    - Sure, In fact you might want multiple `return` statements to specify different end points of a function
5. *What's a local variable?*
    - A variable that's defined in a scope. All variables defined in a function are local variables; they're local to the function
6. *What does it mean to hide a variable?*
    - A variable is hidden when you declare it inside a new scope with the same name as a variable in an outer scope. As a reuslt, you can't get to the variable i the outer scope by using its variable name in the inner scope
7. *When does a variable go out of scope?*
    - A variable goes out of scope when the scope in which it was created ends
8. *What does it mean when a variable goes out of scope?*
    - It means the variable ceases to exist
9. *What's a nested scope?*
    - A scope created within an existing scope
10. *Must an argument have the same name as the parameter to which it's passed?*
    - No. You're free to use different names. It's only the value that's passed from a function call to a function
11. *Can I write one function that calls another?*
    - Of course, In fact, whenever you write a function that you call from `main()`, your doing just that. In addition, you can write a function (other than `main()` that calls another function)
12. *What is code profiling?*
    - It's the process of recording how much CPU time various parts of the program use
13. *Why profile code?*
    - To determine any bottlenecks in a program. Sometimes it makes sense to revisit these sections of code in an attempt to optimise them
14. *When do programmers profile code?*
    - Usually towards the end of the programming of a game project
15. *What's premature optimisation?*
    - An attempt to optimise code to early in the development process. Code optimisation usually makes sense near the end of programming a game project
