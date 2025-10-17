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

## Notes

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
