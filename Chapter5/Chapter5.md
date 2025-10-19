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

>[!CAUTION]
>A function definition much match its prototype on return type and function name, otherwise a compile error is generated

### Calling Functions

- Functions are called the same way as those we've already worked with, e.g. `function(params)`
- Control jumps to the function
  - The function then executes
  - After the function finishes control returns to the calling code

### Understanding Abstraction

- Functions are a form of implementing *abstraction*
- Abstraction helps you focus on the big picture
  - i.e. a function call is an interface / contract
    - We supply a given set of arguments (*preconditions*)
    - The function does some work, maintaining some properties (*invariants*)
    - Side effects occur or values are returned (*postconditions*)
    - **Note:** Preconditions, invariants and postconditions are a bit more complicated than this but this the general idea.
  - We can focus on what we have to send to the function, and what it does, without having to focus on the *how* or the internal function implementation

### Using Parameters and Return Values

- You can provide a function values (*parameters*)
- You can receive data back (*return values*)
- e.g. `toupper(char c)` takes in a character, and returns the uppercase version
- This allows functions to *communicate*

### Example [Yes or No](#yes-or-no)

### Returning a Value

- To return a value you need to specify a *return type*
- The function must then return a value of that type

#### Specifying a Return Type

- e.g. `char askYesNo1();` defines a function `askYesNo1` that returns a `char`

#### Using the `return` statement

- A value is returned through the `return` statement with the syntax `return value;`
- Return value much match the type of the function definition
- A function ends whenever it hits a `return` statement
  - A function can have multiple `return` points

>[!TIP]
>You don't have to return a value with a `return` statement (unless the function has a *return-type*.) You can use `return` by itself in a function that returns no value (one that indicates `void` as its return type) to end the function

#### Using a Returned Value

- Function values can be thought of as replacing the call `function(values)` with the returned value.
- If you want to keep a function's return value then you need to assign it to a variable

### Accepting Values into Parameters

- You can send functions values that it accepts into its parameters

#### Specifying Parameters

- Parameters are declared in the prototype, e.g. `char askYesNo2(string question)` declares a function `askYesNo2` returning a char and taking in a `string`
  - Example accepts a string and calls that parameter `question`

>[!WARNING]
>You don't have to use parameter names in a prototype; all you have to include are the parameter types. For example, the following is a perfectly valid prototype that declares `askYesNo2`, a function with one `string` parameter that returns a `char`
>
>```cpp
>char askYesNo2(string);
>```
>
>Even though you don't have to use parameter names in prototypes, it's a good idea to do so. It makes your code clearer, and it's worth the minor effort

- Unlike prototypes, you must specify parameter names in a function definition

>[!CAUTION]
>The parameter types specified in a function prototype must match the parameter types listed in the function definition. If they don't you'll generate a compile error

#### Passing Values to Parameters

- Function values are passed in the parentheses, in the order they defined, e.g. the below code snippet calls `askYesNo2` with a value of `"Do you wish to save your game?"` passed to the parameter `question`

```cpp
askYesNo2("Do you wish to save your game?")
```

#### Using Parameter Values

- Parameters are treated like variables, just refer to their name

>[!IMPORTANT]
> Actually, there's a little more going on behind the scenes here. When the string literal `"Do you wish to save your game?"` is passed to `question`, a `string` object equal to the string literal is created and the `string` object gets assigned to `question`

### Understanding Encapsulation

- No variable created in a function, including parameters can be accessed outside the function
  - This is an example of *encapsulation*
- Encapsulation keeps independent details of programs seperate by hiding or *encapsulating* the details
  - Parameters and return values are the mechanisms of intercommunication
  - Only the nessecary information is exchanged
- Encapsulation is closely related to abstraction
  - Encapsulation is a form of abstraction
  - Abstraction = *don't worry about the details*
  - Encapsulation = *hide the details*

### Understanding Software Reuse

- You can reuse functions in other programs, e.g. we could reuse `askYesNo` in every program that needed it

>[!NOTE]
>It's always a waste of time to reinvent the wheel, so *software reuse* (employed existing software and other elements in new projects), is a technique that game companies take to heart. The benefits of software reuse include
>
>- **Increased company productivity**: By reusing code and other elemnets that already exist, such as a graphics engine, game companies can get their projects done with less effort
>- **Improved software quality**: If a game company already has a tested piece of code, such as a networking module, then the compnay can reuse the code with the knowledge that its bug free
>- **Improved software performance**: Once a game company has a high-performance piece of code, using it again not only saves the company the trouble of reinventing the wheel, it saves then from reinventing a less, efficient one

- You can reuse code by copying from one program to another
- Another technique (seen in [Chapter 10](../Chapter10/Chapter10.md)) is to divide a project up into multiple files
- An even more advanced technique (not covered here) is to package code up as *libraries*

### Working with Scopes

- A *scope* is where a variable can be seen in your program

### Example [Scoping](#scoping)

- When you use curly braces to open a block, you create a new *scope*
  - This includes functions
- Variables declared in a scope aren't visible outside of that scope
- Variables declared inside a function are sometimes called *local variables*
  - This includes variables in `main`
- Variables in a lower scope may *shadow* variables in a higher scope if they share the same name.

>[!CAUTION]
>Although you can declare variables with the same name in a series of nested scopes, it's not a good idea because it can lead to confusion

- Once a scope ends, all of the variables declared in that scope cease to exist
  - Referred to as going *out of scope*

>[!TIP]
>Parameters act just like local variables in functions

### Working with Nested Scopes

- Nested scopes are created by nested curly braces

>[!WARNING]
>When you define variables inside `for` loops, `while` loops, `if` statements, and `switch` statements, these variables don't exist outside their structures. They act like variables declared in a nested scope. For example, in the following code, the variable `i` doesn't exist outside the loop
>
>```cpp
>for (int i = 0; i < 10; ++i) {
>   cout << i;    
>}
>// i doesn't exist outside the loop
>```
>
>But beware; some older compilers don't properly implement this functionality of standard C++. The best thing to do is to use a modern compiler

### Using Global Variables

- *Global Variables* are variables that are accessible in any part of a program

### Example [Global Reach](#global-reach)

### Declaring Global Variables

- Global variables are defined outside of any function in a program
  - This includes `main`
  - Must be declared before first use

### Accessing Global Variables

- Global variables can be accessed from anywhere

#### Hiding Global Variables

- Global variables can be shadowed like local variables with nested scopes
  - The global variable can then not be accessed or changed

>[!CAUTION]
>Although you can declare variables in a function with the same name as a global variable, it's not a good idea because it can lead to confusion

### Altering Global Variables

- Since they can be accessed from anywhere this means they can be changed from anywhere

### Minimising the Use of Global Variables

- You should avoid using global variables
- They create hidden dependencies between different parts of the codebase
  - Makes it harder to keep track of state changes

### Using Global Constants

- *Global constants* i.e. declarations with the `const` keyword can make code clearer to read

>[!CAUTION]
>Just like with global barables, you can hide a global constant by declaring a local constant with the same name. However, you should avoid this because it can lead to confusion

- Global constants help by removing *magic values*, embedded literal values in the code
  - These are hard to change correct because say there is a $10$ in the program, but multiple constants with the same value $10$, without a semantic label, how do we know which constant this $10$ references
  - They assign semantic meaning, when you come back to modify the code are you going to remember what a constant was supposed to represent?

>[!CAUTION]
>Just like with global variables, you can hide a global constant by declaring a local constant by declaring a local constant with the same name. However, you should avoid this because it can lead to confusion

### Using Default Arguments

- What happens if we write a function where a parameter is called with the same value almost all of the time?
  - We can define a *default argument*, a value assigned if none is specified

### Example: [Give Me a Number](#give-me-a-number)

### Specifying Default Arguments

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
