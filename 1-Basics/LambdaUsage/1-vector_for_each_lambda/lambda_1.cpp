#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    // Usually we use lambda with std::foreach  (for each is inside algorithm library)

    std::vector<int> values{2, 6, 3, 6, 4, 11, 5, 21};

    // make anonymos function using lambda to return if a number in vector.
    // we use the foreach to loop from the beginning of vector elements till the end, and for each element it picks up, it will pass that element to third part in the forech which the lambda expression that will use the element as input.

    // the element is passed to the lambda expression parameter either by value or by reference
    // Lambda function is just an anonymous function that do some logic on the passed parameters,  [capture closet](parameters){ logic on parameters}
    // capture closet [=] means to receive the elements passed to the function by value, and it means that we can't change the parametes inside the lambda, they passed as if constant values.
    // capture closet [&] means to receive the elements passed to the function by reference, so we can change the parametes inside the lambda.

    std::for_each(values.begin(), values.end(), [=](int x)
                  { std::cout << x << std::endl; });
    return 0;
}
