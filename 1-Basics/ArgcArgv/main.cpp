#include <iostream>

int main( int argc, char** argv)
{
    std::cout << "Num of input items are: " << argc << std::endl;
    std::cout << "Input items are: " << std::endl;

    for ( int num = 0; num < argc; num++ )
        std::cout << " " << argv[num] << std::endl;

    return 0;
}