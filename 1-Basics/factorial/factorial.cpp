#include <iostream>

int factorial(int input_number)
{   
    if (input_number == 1)      //O(1)
        return 1;              
    else
        return (input_number * factorial(input_number-1));   // O(!n)
}

int main(int argc, char* argv[])
{   
    int input_number;
    std::cout << "Program to calculate the factorial" << std::endl;

    std::cout << " what number you want to calculate the factorial for?  ";
    std::cin >> input_number;
    std::cout << "The calculated factorial is: " << factorial(input_number) << std::endl;

    return 0;
}