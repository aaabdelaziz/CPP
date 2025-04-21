#include <iostream>
#include <vector>
#include <algorithm>

// https://www.youtube.com/watch?v=XIwssRWbksA&list=PLDlH6NfW8TnBaPG9R4-aLbeB8cvBVdTmD&index=15

using namespace std;

int main()
{

    int x = 10;
    int y = 2;
    std::vector<int> sum;

    // Usually we use lambda with std::foreach  (for each is inside algorithm library)
    std::vector<int> values{2, 6, 3, 6, 4, 11, 5, 21};

    // will pass all outscope variables as constants  values to lambda, but due to mutable keyword, we will be able to modify x and/or y
    [=]() mutable noexcept
    {
        // vector_elem will carry each vector element
        std::for_each(values.begin(), values.end(), [&](int vector_elem)
                      {
                          x += 5;   // 15
                          y += 2;   // 4
                          sum.push_back(x + y + vector_elem); });

        std::cout << " the sum vector values inside lambda are: " << std::endl;
        for (auto elem : sum)
            std::cout << elem << " ";
    }();

    // the sum outside the lambda is totally different than that inside the lambda,
    // because we just copied the sum vector (wich was empty) by value from outside scope to the lambda at line 18,
    // this is done when I made [=], then the word mutable means that all the copies made by value for the outside scope variables can be modified inside the lambda, but it will not affect the original values outside lambda.
    // then, inside it, I made a for loop
    std::cout << "\n the sum vector values outside lambda are: " << std::endl;
    for (auto elem : sum)
        std::cout << elem << " ";

    return 0;
}
