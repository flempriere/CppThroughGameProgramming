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

## Notes

### Using C++ for Games

- It's fast
- It's flexible
- It's well-supported.

### Creating an Executable File

- C++ is a compiled language, meaning code must be converted from the higher level language to machine-executable code. The process roughly follows

1. Write *source code*.
2. Compile *source code* to an *object file*.
3. Link *object files* to *external files* to form an *executable file*
4. Execute the *executable file*

### Dealing with Errors

There are three common error categories

1. **Compile Errors:**
    - Occur during code compilation
    - *object file* is not produced
    - Typically *syntax errors* where the compiler can't interpret the code
    - Sometimes you may get *warnings* not *errors*
        - *Warnings* typically don't prevent compilation but should generally be fixed.
        - The compiler `g++` has the flag `-Werror` to treat *warnings* as *errors*
2. **Link Errors:**
    - Occur during linking
    - Typically indicate an external reference can't be found
    - Often need to adjust the reference and *recompile*
3. **Runtime Errors:**
    - Occur when the *executable* is run
    - Program may crash due to *illegal* action
    - More subtle is a *logic error*
        - Code behaves in an incorrect or unexpected way
        - Called a *bug*!

>[!NOTE]
> Like other software creators, game companies work hard to produce bug-free products. Their first line of defence is the quality assurance personnel (game testers). Game testers play games for a living, but their jobs are not as fun as you might think. Testers must play the same parts of a game over and over (perhaps hundreds of times) trying the unexpected and meticulously recording anomalies. On top of monotonous work, the pay ain't great either. But being a tester is a terrific way to get into a game company on the proverbial bottom rung.

### The ISO Standard

- Describes the specification of the language
- Defines a group of files, the *standard library* that contain common programming building blocks e.g. I/O support

>[!TIP]
> The ISO standard is often called the *ANSI Standard* or *ANSI/ISO Standard.* These different names involve the acronyms of the various committees that have reviewed and established the standard. The most common way to refer to C++ code that conforms to the ISO standard is simply *Standard C++.*

### Writing your First C++ Program

#### Example [Game Over v1](#game-over-v1)

#### Commenting Code

- `//` marks the remainder of a line as a comment, it is ignored by the compiler
- Comments are to help inform intentions

#### Using Whitespace

- Whitespace is not *significant* in C++. It is ignored by the compiler
- Whitespace is thus useful for making a program clearer
  - Like paragraphs in a written document

#### Including Other Files

- Lines beginning with `#` denote *preprocessor* directives
- The *preprocessor* runs before the compiler and substitutes text based on provided directives
- `#include <file>` tells the *preprocessor* to include the contents of `file` in the current file
- `iostream` is a standard library file containing code for handling *streams* which lets us display output
- Included files are referred to as *header files*

#### Defining the `main()` Function

- `int main()` defines a function called `main`
- A function is a group of code that performs some work and may *optionally* return a value
- All function headers have `()` after the name
- All C++ programs must have a `main` function
  - Program execution starts at `main`
- Functions are delimited by `{}`
  - Code between any `{}` is referred to as a *code block*
  - Typically indented to show a distinct unit
  - block making up an entire function is called the *body* of the function

#### Displaying Text through the Standard Output

- The line `std::cout << "Game Over!" << std:: endl` displays `Game Over!` followed by a newline
- `"Game Over!"` is referred to as a *string* (a sequence of characters)
  - Since it is literally he characters in quotes this specifically is a *string literal*
- `cout` is an object from `iostream` that sends data to the *standard output stream* (typically the console window)
  - The output operator `<<` sends contents on its right to `cout`
- `cout` lives in the standard library in a *namespace* called `std` so to access it we have to prefix it with the namespace followed by `::` like `<namespace>::` in this case `std::`
  - Namespaces help prevent collisions between identically named objects in different contexts
- `endl` also lives in the `std` namespace and is defined in `iostream`. Sending `endl` to `cout` ends the current line

#### Terminating Statements

- C++ code is made up of statements, statements must be terminated with a semicolon `;`.

#### Returning a Value from `main()`

- `return 0` returns $0$ from the `main` function. Returning from `main` returns control and the value $0$ to the operating system.
- Returning $0$ from `main` is a standard convention to indicate that a program finished without any issues.

>[!WARNING]
> When running a console program in a seperate window, you may see a console window appear and disappear quickly. That's likely because the program finishes execution almost instantly and closes the window. In windows you can use a batch file that runs your console program.
>
>For example the compiled program from the [game over](#game-over) example is called `game_over.exe`. You can create a batch file comprised of the lines
>
>```batch
>game_over.exe
>pause
>```
>
> To create a batch file:
>
>1. Open a text editor
>2. Type your text
>3. Save the file with a .bat extension
> Finally run the batch file and the program should run then pause with the window still open. On Linux running the program in a terminal should avoid this problem.

### Working with the Std Namespace

- Often we work with objects in the same namespace constantly. There are two methods to avoid having to use the `<namespace>::` construct everytime we wish to access these objects

#### Example [Game Over 2.0](#game-over-v2)

- Produces the exact same results as [Game Over v1](#game-over-v1)

#### Employing a `using` Directive

- The line `using namespace <namespace>` here `using namespace std;` *imports* the namespace `std`
  - Can now access **all** members of the namespace without using the `<namespace>::std` prefix

#### Example [Game Over 3.0](#game-over-v3)

#### Employing `using` Declaration

- The line `using <namespace>::<element>` specifies a specific element from a namespace that we wish to *import*
  - e.g. `using namespace std::cout` and `using namespace std::endl` let us refer to `std::cout` as `cout` and `std::endl` as `endl` respectively
- This technique clearly identifies which elements are being used
  - Also doesn't import unused elements

#### When to employ `using`

- Best practice arguably to never use `using` and stick to prefixing (since namespaces are there to prevent name collisions).
  - In `C` there is no namespacing so convention is to name library code as `LIBRARY_function_name` which shows how prevelant name collisions can be.
- `using` declarations are the safer option over importing the entire namespace when you are unsure about potential collisions
- The book generally uses `using namespae std` largely for brevity and because the examples are small toy examples

>[!NOTE]
> When you're working on a project, whether it's in the classroom or in the professional world, you'll probably receive coding standard created by the person in charge

### Using Arithmetic Operators

#### Example [Expensive Calculator](#expensive-calculator)

#### Adding, Subtracting and Multiplying

- Behaves as you would expect using the `+, -` and `*` symbols
- Each arithmetic operation is part of an *expression*
  - Expressions are *evaluated* to a single *value*
  - This value may be passed around, e.g. to `cout`

#### Understanding Integer and Floating Point Division

- Integer division in C++ preserves the type, i.e. the result is an integer.
- Division is thus truncated
  - e.g. `7 / 3 = 2` not `2.333...`
- Floating point division does not truncate, and can be forced by making one of the arguments a `float` (number with a fractional part)
  - e.g. `7.0 / 3.0 = 2.33333`

>[!CAUTION]
>While the result of `7.0 / 3.0` (`2.33333`) contains a fractional part, it is still truncated. (The true result would stretch out $3$ after the decimal point forever.) It's important to know that computers generally store only a limited nummber of significant digits for floating point numbers. However, C++ offers categories of floating point numbers to meet the most demanding needs (even those of computationally intensive 3D games.)

#### The Modulus Operator

- The modulus operator `%` returns the remainder of integer division

#### Understanding Order of Operations

- C++ expressions are evaluated left to right in order of precedence
- Some operators have higher precedence
- e.g. like in mathematics, multiplication, division and modulus preceed addition and subtraction
- Like in Mathematics, parentheses `()` can be used to modify precedence

#### Declaring and Initialising Variables

- A *variable* represents a piece of memory
  - Can store, retrieve and manipulate data

#### Example [Game Stats](#game-stats-v1)

#### Understanding Fundamental Types

- *Variables* have a *type*
- *Type* defines what kind of information is stored
  - Tells the compiler how much memory to reserve
  - Defines what operations are allowed on the variable
- *Fundamental Types* are those built into the language
  - *bool* - true or false values
  - *char* - single character values
  - *int* - for integers
  - *float* - for single precision floating point
  - *double* - for double precision floating point

#### Understanding Type Modifiers

- *Modifiers* can be attached to a type
  - *short* reduces the numerical range (and potentially size) of a variable
    - May modify an *int*
  - *long* increases the numerical range (and potentially size) of a variable
    - May modify an *int* or a *double*
  - *signed* and *unsigned* work for integer types
    - *signed* may store positive and negative values
    - *unsigned* may only store positive values and zero
    - By default variables are *signed*

>[!CAUTION]
>The range of values stored in a given type may be compiler and machine dependent. The provided table is only an example

| Type               | Range                                  |
|--------------------|----------------------------------------|
| short int          |                        -32768 to 32767 |
| unsigned short int |                             0 to 65535 |
| int                |              -2147483648 to 2147483647 |
| unsigned int       |                        0 to 4294967295 |
| long int           |              -2147483648 to 2147483647 |
| unsigned long int  |                        0 to 4294967295 |
| float              | 3.4E +/- 38 (seven significant digits) |
| double             |   1.7E +/- 308 (15 significant digits) |
| long double        |   1.7E +/- 308 (15 significant digits) |
| char               |                   256 character values |
| bool               |                          true or false |

>[!TIP]
>`short int` may be written as `short` and `long int` may be written as `long`

#### Declaring Variables

- A variable declaration follows the format `<type> <name>`
  - e.g. `int score;` declares a *integer* named `score`.
- Multiple variables can be declared on one line
  - e.g. `short lives, aliensKilled` declares two integers, one called `score` and another called `aliensKilled`.

#### Naming Variables

- There are a limited number of rules for variable names
  - May only contain numbers, letters and underscores
  - Can't start with a number
  - Can't be a C++ keyword
- A *keyword* is a special word reserved by C++ for its own use

Common guidelines for naming a variable are

1. **Be Descriptive**
    - A variable should describe what it represents
2. **Be Consistent**
    - Variables should follow the same naming conventions as each other
3. **Follow the Language Traditions**
    - Idioms are conventions used by programmers
    - In C++ start variables with a lowercase letter
    - Don't use underscore as the first character
4. **Keep the Length in Check**
    - Variable names should be succinct
    - *However* note that it is more important to be *descriptive!*

>[!TIP]
> *Self-documenting code* is written in such a way that it's easy to understand what is happening in the program independent of any comments. Choosing good variable names is an excellent step towards this kind of code

#### Variable Assignment

- Variables are assigned using the syntax `<name> = <value>`
- Note that for characters the value must be wrapped in `''`
  - `char c = 'y'` assigns the character `y` to `c`
  - `char c = y` tries to assign the value of a variable `y` to `c`

#### Initialising Variables

- You can declare an initialise a variable in one statement.
  - e.g. `double engineTemp = 6572.89` initialises and assigns to the double `engineTemp`

>[!WARNING]
> Although you can declare a variable without assigning it a value, it's best to initialise a new variable with a starting value whenever you can. This makes your code clearer, plus it eliminates the chance of accessing an uninitalised variable which may contain any value

#### Displaying Variable Values

- Variables can be sent to `cout` to display their values

>[!TIP]
>An *escape sequence* is a pair of characters beginning with a backslash (`\`), which represent special printable characters.
>
>```Cpp
>`cout << "\nscore: " << score << endl;
>```
>
>The escape sequence `\n` represents a newline. When sent to `cout` as part of a `string`, it starts a newline. Similarly `\t` is the escape sequence for a horizontal tab

#### Getting User Input

- `cin` is the standard input counterpart to `cout`
- `cin >> fuel` reads from standard input into the variable `fuel`
- `cin` also lives in `iostream` and `std`
- `>>` is called the *extraction operator*

#### Defining New Names for Types

- You can define new types or *alias* old types using `typedef`
- e.g. `typedef unsigned short int ushort` alias the `unsigned short int` type as `ushort`
- Syntax is `typedef <current type> <new type>`

#### Which Types to Use

- `int` typically the most efficiently sized integer type
- `unsigned int` useful if a larger non-negative range is needed
- `double` is the standard floating point type these days
  - Though `float` may be more efficient depending on the system

#### Performing Arithmetic Operations with Variables

#### Example [Game Stats 2.0](#game-stats-v2)

>[!CAUTION]
> When you compile the program you may get a warning similar to, "Warning: this decimal constant is unsigned." Fortunately the warning does not stop the compilation process. This warning is the result of *integer wraparound* that should be avoided; here the wraparound is intentional to demonstrate the behaviour

#### Altering the Value of a Variable

- Use assignment operator `=`
- Can include references to self in the righthand expression
  - e.g. `score = score + 100` calculates the value of *score* plus one hundred and assigns the value back to *score*

#### Using Combined Assignment Operators

- Have the form `<name> <operator>= <expression>` and are equivalent to `<name> = <name > <operator> (<expression>)`

#### Using Increment and Decrement Operators

- There are two increment operators `++x` and `x++`
  - `++x` increments `x` *before* evaluating the parent expression
  - `x++` increments `x` *after* evaluating the parent expression
- These operators are referred to as the *pre* and *post*fix operators
- Equivalents exist for subtraction

#### Dealing with Integer Wrap Around

- Increasing an integer beyond its maximum value wraps it around to its minimum value
- Decrementing an integer beyond its minimum value wraps it around to its maximum value

>[!WARNING]
>Make sure to pick an integer type that has a large enough range for its intended use

#### Working with Constants

- A constant is a fixed named value
- They are useful for capturing frequently referencing unchanging values
- Constants make the program clearer by providing semantic meaning
- Constants make change easy by localising the change to one value

#### Example [Game Stats 3.0](#game-stats-v3)

#### Using Constants

- Constants are declared the same way as variables
- By convention they are written in all uppercase letters
- Prefixed by the *keyword* `const`
  - e.g. `const int ALIEN_POINTS = 150;` declares the integer constant `ALIEN_POINTS` and sets it equal to $150$
- Constants may be referred to like any other value

>[!CAUTION]
> Attempting to assign a new value to a constant results in a **compile error**

#### Using Enumerations

- A set of `unsigned int` constants, called *enumerators*
- Typically related and ordered
  - e.g. `enum difficulty {NOVICE, EASY, NORMAL, HARD, UNBEATABLE}`
- By default values start at $0$ and increase by $1$
- Enum syntax is `enum <name> {values}`
- The enum acts as a type, e.g. we can declare a variable of that type
  - `difficulty myDifficulty = EASY`
- The programmer may define the values of the *enumerators* using the syntax `{<enumerator>=<value>}`
  - Enumerators that are not assigned a value will be assigned the value of the previous enumerator + $1$ (or zero if they are the first)

### Introducing [Lost Fortune](#major-project-lost-fortune)

- Personalised Adventure in which the player provides some information to enhance a basic adventure story
- The include `#include <string>` includes `string` a library that provides `string` objects for handling sequences of *characters*

>[!CAUTION]
> `cin >> <string variable>` only works for strings that have no whitespace in them (e.g. tabs or spaces). There are ways to compensate for this, but that requires an understanding of *streams* which are beyond the scope of this chapter

## Summary

- C++ is the primary language used in AAA game programming
- A program is a series of C++ Statements
- The basic lifecycle of a C++ program is idea, plan, source code, object file, executable
- Programming errors tend to fall into three categories
  1. Compile Errors
  2. Link Errors
  3. Runtime Errors
- A function is a group of programming statements that can do some work and return a value
- Every program must contain a `main()` function, which is the starting point of the program.
- The `#include` directive tells the preprocessor to include another file in the current one
- The standard library is a set of files that you can include in your program files to handle basic functions like input and output
- The `std` namespace includes elements from the standard library. To access an element from the namespace, you need to prefix the elements with `std::` or employ `using`
- `cout` is an object, defined in the file `iostream`, that's used to data to the standard output stream
- `cin` is an object, defined in the file `iostream`, thats used to get data from the standard input stream
- C++ has built in arithmetic operators
- C++ defines fundamental types for Boolean, single-character, integer and floating-point vlaues
- The C++ standard library provides a type of object (`string`) for strings
- You can use `typedef` to create a new name for an existing type
- A constant is a name for an unchangeable value
- An enumeration in a sequence of `unsigned int` constants

## Questions and Answers

1. Why do game companies use C++?
    - C++ combines speed, low-level hardware access and high-level constructs as well as lots of developed code and tooling
2. How is C++ different to C
    - C++ is an evolution of C. C++ retains most of C, but contains mechanisms or heuristics that are different to its sister language, including support for object-oriented programming
3. How should I use comments?
    - To explain code that is unusual or unclear
4. What's a programming block?
    - One or more statements surrounded by curly braces to form a single unit
5. What's a compiler warning?
    - A message from your compiler stating a potential problem. A warning will not stop the compilation process
6. Can I ignore compiler warnings?
    - You can, but you shouldn't. You should address the warning and fix the offending code
7. What is whitespace?
    - A set of non-printing characters that create space in your source files, including tabs, spaces and newlines
8. What are literals?
    - Elements that represent explicit values
9. Why should I always try to initialise a new variable with a value?
    - Because the contents of an unitialised variable could be any value; even one that doesn't make sense for a program
10. Why do programmers sometimes use variable names such as `myInt` or `myFloat`?
    - To clearly spell out a variables type. This is typically only used for teaching purposes
11. What are variables of type `bool` for?
    - They can represent a true or false condition e.g. if a playing card is face up
12. How did the `bool` type get its bame?
    - The type is named after the english mathematician *George Boole*
13. Must the names of constants by in uppercase?
    - No, but it is the accepted convention
14. How can I store more than one character with a single variable?
    - Use a string object
