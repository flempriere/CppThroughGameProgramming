# Beginning C++ Through Game Programming

This repository contains code fragments, notes and exercises from the book Beginning C++ Through Game Programming, Third Edition by Michael Dawson.

I started this repository as a way to mix up working through some more challenging algorithms textbooks while learning some (albeit outdated) C++.

## Structure

This repository has been broken down by Chapter. Each Chapter contains a markdown file following the following structure,

Each Chapters markdown file is broken down into

1. *Examples* - Links and descriptions of code fragments provided by the books
2. *Exercises*
    1. **Discussion Questions and Answers** - Contains the discussion question, and an answer. Some of these are personal opinion and taste and you should consider your own reponse too
    2. **Code Examples** - Contains a description of the exercise, a link to a code implementation and an explanation of the solution
3. *Notes* - Short abbreviated notes from the main body of the chapter
4. *Summary* - Summary dot points provided at the end of a chapter
5. *Questions and Answers* - Provided Questions and Answers from the chapter

In addition, the book often contains asides according to a series of classifications. To make these stand out in the notes like the book, we have used github-flavoured markdown alerts. Since the translation is not one to one with the terminally of the book we use the rough translation,

- *Hint* - Good ideas that will help you become a better programmer

>[!WARNING]
>A hint that *warns* about potential poor practice

or,
>[!TIP]
>A hint that *encourages* potential good practice

or,
>[!IMPORTANT]
>A hint that falls into neither category

- *Trap* - These point out areas where its easy to make a mistake

>[!CAUTION]
>Traps use the caution label

- *Trick* - These suggest techniques that will make your life as a game programmer easier

>[!TIP]
>Tricks, similar to helpful *hints* use the **tip** action

- *Real World* - These are facts about the real world of game programming

>[!NOTE]
> Comments about the *Real World* game programming industry use the **note** action

## Content

1. [Chapter 1](./Chapter1/Chapter1.md) - Types Variables and Standard I/O: [Lost Fortune](./Chapter1/Chapter1.md#major-project-lost-fortune)
2. [Chapter 2](./Chapter2/Chapter2.md) - Truth, Branching and the Game Loop: [Guess My Number](./Chapter2/Chapter2.md#major-project-guess-my-number)
3. [Chapter 3](./Chapter3/Chapter3.md) - For Loops, Strings and Arrays: [Word Jumble](./Chapter3/Chapter3.md#major-project-word-jumble)
4. [Chapter 4](./Chapter4/Chapter4.md) - The Standard Template Library: [Hangman](./Chapter4/Chapter4.md#major-project-hangman)
5. [Chapter 5](./Chapter5/Chapter5.md) - Functions: [Mad Lib](./Chapter5/Chapter5.md#major-project-mad-lib)
6. [Chapter 6](./Chapter6/Chapter6.md) - References: [Tic-Tac-Toe](./Chapter6/Chapter6.md#major-project-tic-tac-toe)
7. [Chapter 7](./Chapter7/Chapter7.md) - Pointers: [Tic-Tac-Toe 2.0](./Chapter7/Chapter7.md#major-project-tic-tac-toe-20)
8. [Chapter 8](./Chapter8/Chapter8.md) - Classes: [Critter Caretaker](./Chapter8/Chapter8.md#major-project-critter-caretaker)
9. [Chapter 9](./Chapter9/Chapter9.md) - Advanced Classes and Dynamic Memory: [Game Lobby](./Chapter9/Chapter9.md#major-project-game-lobby)
10. [Chapter 10](./Chapter10/Chapter10.md) - Inheritance and Polymorphism: [Blackjack](./Chapter10/Chapter10.md#major-project-blackjack)

## Code Style

Generally each Chapter is treated by restricting oneself to the parts of the language as presented in the book up to that point. Where we deviate from this we will generally make reference to doing so. This is typically done where changes in the standard have deprecated some behaviour the book relies on (or the occasional typo correction)
