https://www.youtube.com/watch?v=UYYoq784pQY

/*A constructor is a member function of a class which initializes objects of a
 class. In C++, Constructor is automatically called when object(instance of
 class) create. It is special member function of the class. How constructors are
 different from a normal member function?

        A constructor is different from normal functions in following ways:
        Constructor has same name as the class itself Constructors don�t have
 return type. A constructor is automatically called when an object is created.
    If we do not specify a constructor, C++ compiler generates a default
 constructor for us (expects no parameters and has an empty body).
 *
 * Types of constructors:
 * 1-Default Constructors:
 * -------------------------
 * Default constructor is the constructor which doesn't take any argument.
 * It has no parameters.
 *
 * 2-Parameterized Constructors:
 * ------------------------------
 * It is possible to pass arguments to constructors.
 * Typically, these arguments help initialize an object when it is created.
 * To create a parameterized constructor, simply add parameters to it the way
 * you would to any other function.
 * When you define the constructor�s body, use the parameters to initialize
 * the object.
 * Uses of Parameterized constructor:
 * It is used to initialize the various data elements of different objects
 * with different values when they are created.
 * It is used to overload constructors.
 * Can we have more than one constructors in a class?
 * Yes, It is called Constructor Overloading.
 *
 * 3-Copy Constructor:
 * --------------------
 * A copy constructor is a member function which initializes an object
 * using another object of the same class. Detailed article on Copy
 * Constructor.
 *
 * When is copy constructor called?
 * In C++, a Copy Constructor may be called in following cases:
 * 1. When an object of the class is returned by value.
 * 2. When an object of the class is passed (to a function) by value
 *  as an argument.
 * 3. When an object is constructed based on another object of the same class.
 * like:
 *    base obj1;
 *    base obj2 = ob1;    // copy constructor call when assigning an obj to another at creation time
 * Or
 * 	  base obj2(obj1)     // copy constructor call when assigning an obj to another at creation time
 * 4. When the compiler generates a temporary object.
 * It is, however, not guaranteed that a copy constructor will be called
 * in all these cases, because the C++ Standard allows the compiler to
 * optimize the copy away in certain cases, one example is the return value
 * optimization (sometimes referred to as RVO).
 * Source: https://www.geeksforgeeks.org/g-fact-13/
 *
 * Deep and Shallow Copying
 * ----------------------------
 * Default constructor does only shallow copy.
 * Deep copy is possible only with user defined copy constructor.
 * In user defined copy constructor, we make sure that pointers (or references)
 *  of copied object point to new memory locations.
 *
 *  Copy constructor vs Assignment Operator
 *  ----------------------------------------
 *  Which of the following two statements call copy constructor
 *  and which one calls assignment operator?
 *  MyClass t1, t2;
 *  MyClass t3 = t1;  // ---assignment operator -> (1)
 *  t2 = t1;          // ---copy const--> (2)
 *
 *  When is user-defined copy constructor needed?
 *  If we don�t define our own copy constructor,
 *  the C++ compiler creates a default copy constructor for each class
 *  which does a member-wise copy between objects.
 *  The compiler created copy constructor works fine in general.
 *  We need to define our own copy constructor only if an object has pointers
 *  or any runtime allocation of the resource like file handle, a network
 *  connection..etc.
 *
 * */

// Cpp program to illustrate the
// concept of Constructors
#define CopyConstNeeded

#ifdef Default

#include <iostream>
        using namespace std;

class construct {
public:
  int a, b;

  // Default Constructor
  construct() {
    a = 10;
    b = 20;
  }
};

int main() {
  // Default constructor called automatically
  // when the object is created
  construct c;
  cout << "a: " << c.a << endl << "b: " << c.b;
  return 1;
}

#elif defined(Parametrized)

// CPP program to illustrate
// parameterized constructors
#include <iostream>
        using namespace std;

class Point {
private:
  int x, y;

public:
  // Parameterized Constructor
  Point(int x1, int y1); // constructor declared

  int getX() { return x; }
  int getY() { return y; }
};

Point::Point(int x1, int y1) { // constructor Defined
  x = x1;
  y = y1;
}

int main() {
  // Constructor called
  Point p1(10, 15);

  // Access values assigned by constructor
  cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();

  return 0;
}
#elif defined(CopyConstNeeded)

/* Copy constructor is called when a new object is created from an existing
 * object, as a copy of the existing object.
 * Assignment operator is called when an already initialized object is
 * assigned a new value from another existing object.
 * In the above example (1) calls copy constructor and (2) calls assignment
 * operator.*/

#include <iostream>
#include <cstring>
        using namespace std;

class String {
private:
  char *s;
  int size;

public:
  String(const char *str = NULL);     // constructor
  ~String() { delete[] s; }           // destructor
  String(const String &);             // copy constructor
  void print() { cout << s << endl; } // Function to print string
  void change(const char *);          // Function to change
};

String::String(const char *str) {
  size = strlen(str);
  s = new char[size + 1];
  strcpy(s, str);
}

void String::change(const char *str) {
  delete[] s;
  size = strlen(str);
  s = new char[size + 1];
  strcpy(s, str);
}

String::String(const String &old_str) {
  size = old_str.size;
  s = new char[size + 1];
  strcpy(s, old_str.s);
}

int main() {
  String str1("GeeksQuiz");
  String str2 = str1;

  str1.print(); // what is printed ?
  str2.print();

  str2.change("GeeksforGeeks");

  str1.print(); // what is printed now ?
  str2.print();
  return 0;
}

#elif defined(Ex1)

        class MyClass {
public:
  MyClass(int y); // declaration a non-default constructor

private:
  int x;
};

MyClass::MyClass(int y) { x = y; }

int main() {
  MyClass m(100); // the non-default constructor is called
  MyClass *p; // for pointer declarations, the compiler does not need to know
              // about constructors
  p = new MyClass(); // error at compilation: no default constructor
  return 0;
}
#elif defined(Ex2)

        class MyClass {
public:
  MyClass(int y); // declaration a non-default constructor
  MyClass();

private:
  int x;
};

MyClass::MyClass(int y) { x = y; }

MyClass::MyClass() { x = y; }

int main() {
  MyClass m(100);                   // the non-default constructor is called
  MyClass *pointer = new MyClass(); // at runtime, an object is created, and the
                                    // default constructor is called
  return 0;
}

#endif
