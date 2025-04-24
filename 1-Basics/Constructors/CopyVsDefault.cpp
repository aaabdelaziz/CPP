
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
