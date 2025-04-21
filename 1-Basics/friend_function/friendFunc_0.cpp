#include <iostream>

class MyClass {
private:
    int data;

public:
    MyClass(int d) : data(d) {}

    // Declare the friend function
    friend void friendFunction(const MyClass& obj);
};

// Define the friend function
void friendFunction(const MyClass& obj) {
    // Access private member 'data' of MyClass
    std::cout << "Friend function accessing data: " << obj.data << std::endl;
}

int main() {
    MyClass obj(42);
    friendFunction(obj); // Call the friend function
    return 0;
}
