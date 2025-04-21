#include <iostream>

/*

 L value has a name like 

*/

// Return R-Value 
int Add(int x, int y){
    return x+y;
 
}

// Return L-value
int &Transform(int &x){
    x *=x;
    return x;
}

// Print that will take L-Value reference
void Print(int &x){
    std::cout << "Print(int&) - which accept L-Value Reference" << std::endl;
}

// Print that will take R-Value reference
void Print(int &&x){
    std::cout << "Print(int&&) - which accept R-Value Reference" << std::endl;
}

int main()
{
    int x = 10;

    std::cout << "Sending x=10 (which is L value)" << std::endl;
    Print(x);
    std::cout << "Sending 3 (which is R value)" << std::endl;
    Print(3);
    return 0;
}
