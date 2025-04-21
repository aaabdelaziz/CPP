#include <iostream>

int main()
{

    int x = 20, y = 4;

    // pass all variables in scope outside lambda function by reference
    std::function<void(int, int)> predict = [&]()
    { std::cout << x + y; }

    // call lambda function
    predict(x, y);

    // or you can call it like this
    /*
        function<void(int)> predict = [&]()
        { std::cout << x + y; }()
    */

    return 0;
}
