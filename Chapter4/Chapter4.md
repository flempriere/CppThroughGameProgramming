# Chapter 4: The Standard Template Library

## Examples

### Hero's Inventory

Introduces the concept of dynamic arrays called *vectors* and *iterators* over them

#### [Hero's Inventory 2.0](./Examples/01_HerosInventory/v2/heros_inventory.cpp)

Introduces *vectors* as dynamic arrays

#### [Hero's Inventory 3.0](./Examples/01_HerosInventory/v3/heros_inventory.cpp)

Demonstrates the use of *iterators* to access eleemnts of a container like a *vector*

### [High Scores](.//Examples/02_HighScores/high_scores.cpp)

Demonstrates use of the standard algorithms offered in the STL including operations like *sort* and *random shuffle*

### [Major Project: Hangman](./Examples/03_Hangman/hangman.cpp)

Introduces the concept of *pseudocode* and ties together *vectors* and STL *algorithms* in the game *Hangman* where a player has a limited number of guesses to guess a hidden word from an internal dictionary character by character.

## Exercises

### Discussion Questions

### Code Exercises

## Notes

## Summary

- The Standard Template Library (STL) is a powerful collection of programming code that provides containers, algorithms and iterators
- Containers are objects that let you store and access collections of values of the same type
- Algorithms defined in the STL can be used with its containers and provide common functions for working with groups of objects
- Iterators are objects that identify elements in containers and can be manipulated to move among elements
- Iterators are they key to using containers to their fullest. Many of the container member functions require iterators, and the STL algorithms require them too
- To get the value reference byy an iterator, you must *dereference* the iterator using the *dereference operator (\*)*
- A vector is one kind of sequential container provided by the STL. It acts like a dynamic array
- It's very efficient to iterate through a vector. It's also very efficient to insert or remove an element from the end of a vector
- It can be inefficient to insert or delete elements from the middle of a vector, especially if the vector is large
- Psuedocode, which falls somewhere between English and a programming language is used to plan programs
- Stepwise refinement is a process used to rewrite pseudocode to make it ready for implementation

## Questions and Answers

1. Why is the STL important?
    - Because it saves game programmers time and effort. The STL provides commonly used container types and algorithms
2. Is the STL fast?
    - Definitely. The STL has been honed by hundreds of programmers to eke out as much performance as possible on each supported platform
3. When should I use a vector instead of an array?
    - Almost always. Vectors are efficient and flexible. They do require a little more memory than arrays, but this tradeoff is almost always worth the benefits
4. Is a vector as fast as an array?
    - Accessing a vector element can be just as fast as accessing an array element. Also, iterating through a vector can be just as fast as iterating through an array
5. If I can use the subscripting operator with vectors, why should I ever need iterators?
    - There are several reasons. First, many of the `vector` member functions require iterators. (`insert()` and `erase()` are two examples.) Second, STL algorithms require iterators. And third, you can't use the subscripting operator with most of the STL containers, so you're going to have to learn to user iterators sooner or later
6. Which is the best way to access elements of a vector? Through iterators, or through the subscripting operator?
    - It depends. If you need random-element access, then the subscripting operator is a natural fit. If you need to use the STL algorithms, then you must use iterators
7. What about iterating through the elements of a vector? Should I use subscripting or an iterator?
    - You can use either method. However, an advantage of using an iterator is that it gives you the flexibility to substitute a different STL container in place of a vector (such as a list) without much code changing
8. Why does the STL define more than one sequentional container type?
    - Different sequential container types have different performance properties. They're like tools in a toolbox; each tool is best suited for a different job
9. What are container adaptors?
    - Container adaptors are based on one of the STL sequence containers; they represent standard computer data structures. Although they are not official containers, they look and feel just like them
10. What's a stack?
    - A data structure in which elements are removed in the reverse order from how they were added. This means that the last element added is the first one removed. This is just like a real-life stack, from which you remove the last item you placed on top of the stack
11. What's a queue?
    - A data structure in which elements are removed in th esame order they were added. This is just like a real-life queue, such as a line of people in which the first person in line gets served first
12. What's a double ended queue?
    - A queue in which elements can be added or removed from either end.
13. What's a priority queue?
    - A data structure that supports finding and removing the element with the highest priority
14. When would I use psuedocode?
    - Any time you want to plan to write a program or section of code
15. When would I use stepwise refinement?
    - When you want to get even more detailed with your pseudocode
