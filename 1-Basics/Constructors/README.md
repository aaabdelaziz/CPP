## Constructors in C++

🎥 [Watch the video explanation](https://www.youtube.com/watch?v=UYYoq784pQY)

### What is a Constructor?

A **constructor** is a special member function of a class that is automatically called when an object is created. It is used to initialize the object.

#### Key Differences from Normal Functions:

- Has the same name as the class
- No return type (not even `void`)
- Automatically invoked when an object is created
- Compiler provides a default constructor if none is defined

### Types of Constructors

#### 1. Default Constructor

```cpp
class MyClass {
public:
    MyClass() {
        // Default constructor
    }
};
```

#### 2. Parameterized Constructor

```cpp
class MyClass {
    int x;
public:
    MyClass(int value) {
        x = value;
    }
};
```

**Uses:**
- Initialize objects with different values
- Constructor overloading

#### 3. Copy Constructor

```cpp
class MyClass {
public:
    MyClass(const MyClass& obj) {
        // Copy constructor
    }
};
```

**When Called:**
1. Returning an object by value
2. Passing an object by value
3. Constructing from another object
4. Compiler-created temporaries

🔗 [GeeksforGeeks – Copy Constructor](https://www.geeksforgeeks.org/g-fact-13/)

### Deep vs Shallow Copy

- **Shallow copy**: Default constructor, shared references
- **Deep copy**: User-defined copy constructor with new memory

### Copy Constructor vs Assignment Operator

```cpp
MyClass t1, t2;
MyClass t3 = t1;  // Copy Constructor
t2 = t1;          // Assignment Operator
```

### When to Define a Copy Constructor

Only define one if your class uses:
- Dynamic memory
- External resources (file handles, sockets, etc.)

---