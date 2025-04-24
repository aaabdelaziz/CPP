#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    // Usually we use lambda with std::foreach  (for each is inside algorithm library)

    std::vector<int> values{2, 6, 3, 6, 4, 11, 5, 21};

    // make anonymos function using lambda to return if a number in vector is odd or even
    // we use the foreach to loop from the beginning of vector elements till the end, and for each element it picks up, it will pass that element to third part in the forech which the lambda expression that will use the element as input.

    // the element is passed to the lambda expression parameter either by value or by reference
    // Lambda function is just an anonymous function that do some logic on the passed parameters,  [capture closet](parameters){ logic on parameters}
    // capture closet [=] means to receive the elements passed to the function by value, and it means that we can't change the parametes inside the lambda, they passed as if constant values.
    // capture closet [&] means to receive the elements passed to the function by reference, so we can change the parametes inside the lambda.
    int sum = 0;

    /*
       You have to add the sum to the capture closet in order to allow the lambda function to see
       the sum variable which is out of it's scope, otherwise it will give error
       - From other hand each vector element will be passed to the (x) variable
       - u can imagine as if the lambda make two things, see the other variables out of it's scope and also take input from the for_each, then make an operation on the x from vector and the sum from the outside scope
    */

    // This part will gives compilation error as we passed the sum from out scope to the lambda by value, so we aren't allowed to modify sum.
    // std::for_each(values.begin(), values.end(), [sum](int x)
    //               { sum += x; });
    // std::cout << sum;

    // to change the sum we should pass it by reference so as to be able to modify it
    std::for_each(values.begin(), values.end(), [&sum](int x)
                  { sum += x; });
    std::cout << sum;
    return 0;
}
