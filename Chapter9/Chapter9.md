# Chapter 9: Advanced Classes and Dynamic Memory: Game Lobby

## Examples

### [Critter Farm](./Examples/01_CritterFarm/critterFarm.cpp)

Demonstrates object containment, a form of *aggregation*

### [Friend Critter](./Examples/02_FriendCritter/friendCritter.cpp)

Introduces *friend functions* and shows how to implement *operator overloading*

### [Heap](./Examples/03_Heap/heap.cpp)

Demonstrates dynamically allocating memory

## Exercises

## Notes

- C++ gives programmers a high degree of control over memory
- This includes direct memory control
- Here we discuss *dynamic memory*, i.e. memory managed at runtime

### Using Aggregation

- Game objects are typically composed of other others
- In OOP this is described as *aggregation*
  - Combining objects into another

#### Example [Critter Farm](#critter-farm)

#### Using Object Data Members

- One form of aggregation is declaring a data member that holds another object
  - e.g. our `Critter` class contains `string` data member `string m_Name`
  - The constructor below, ensures the `string` is properly instantiated
    - The `name` is passed through to the `string` constructor

```cpp
Critter::Critter(const string& name): m_Name(name) {};
```

- Objects can then be accessed like any other data members

#### Using Container Data Members

- Can also use containers
- e.g. our `Farm` class contains a `vector<Critter> m_Critters` to store critters
- Constructor may be more complicated, as we see below
  - Have to be explicit about the desired behaviour

```cpp
Farm::Farm(int spaces) {
    m_Critters.reserve(spaces);
}
```

- Then can be used as any other data member, i.e. access with the `.` operator, then we can call the `vector`'s own functions
- e.g. If we want to add a `Critter` we can use,

```cpp
void Farm::Add(const Critter& aCritter) {
    m_Critters.push_back(aCritter);
}
```

>[!CAUTION]
>`push_back()` adds a copy of an object to a vector; this means that I can create an extra copy of each `Critter` object every time I call `Add`. This is no big deal in the Critter Farm program, but if I were adding many large objects, it could become a performance issue. You can reduce this overhead by say, a vector of pointers to objects. You'll see how to work with pointers to objects later in this chapter

### Using Friend Functions and Operator Overloading

- *Friend Functions* have complete access to any member of a class
- *Operator Overloading* allows you to define meanings for built-in operators as they relate to objects of yyour own class

#### Example [Friend Critter](#friend-critter)

#### Creating Friend Functions

- A friend function can access any member of a class of which its a friend
- A function is specified as a friend using the `friend` as a function prototype *inside* the class definition
  - e.g. The following prototype in the `Critter` class, makes `Peek` a friend of the `Critter` class

```cpp
friend void Peek(const Critter& aCritter);
```

- `Peek` can access any member of `Critter`, even though it's not a member function!

#### Overloading Operators

- Lets you give meaning to built in operators and new types
- e.g. could overload `*` to mean matrix multiplication for a `matrix` class
- To overload an operator, define a function `operatorX` where `X` is the operator to overload
- e.g. Here we overload the `<<` operator

```cpp
ostream& operator<<(ostream& os, const Critter& aCritter) {
    os << "Critter Object - ";
    os << "m_Name: " << aCritter.m_Name;
    return os;
}
```

- `<<` now overloaded so that a `Critter` object send via `<<` to `cout` prints details about `Critter`
  - Use the `friend` functionality to access `Critter`'s internals
- Makes it easy to print a `Critter`
- `cout` is of type `ostream` which also overloads `<<` so that you can send built-in types to `cout`

>[!TIP]
>With all the tools and debugging options available to game programmers, sometimes simply displaying the values of variables is the best way to understand what's happening in your programs. Overloading the `<<` operator can help you do that

### Dynamically Allocating Memory

- All previous programs have used *automatic* memory management
- Variables either declared in the global scope
  - Memory set aside for the entire duration of the program
  - Typically *static* memory
- Variables also declared in function scope
  - Memory set aside for the duration of the *function*
  - Called *stack* memory
- There is an additional form of memory that persists independent of the function calls
  - Must be allocated and deallocated by the programmer
  - Collectively referred to as the *heap*
- The *heap* is good for efficiency
  - Lets you control exactly how much memory you have at a point in time
  - Can create objects in one function that live on after the function returns

#### Example [Heap](#heap)

#### Using the `new` Operator

## Summary

## Questions and Answers
