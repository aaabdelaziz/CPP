#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  // Usually we use lambda with std::foreach  (for each is inside algorithm
  // library)

  std::vector<int> values{2, 6, 3, 6, 4, 11, 5};

  // count number of times that there are even numbers in the vector, it count
  // number of times the if the return was one
  std::cout << "The number of even numbers are"
            << std::count_if(values.begin(), values.end(),
                             [=](int elem) { return (elem % 2 == 0); });

  // count number of times that there are odd numbers in the vector, it count
  // number of times the if the return was one
  std::cout << "The number of odd numbers are"
            << std::count_if(values.begin(), values.end(),
                             [=](int elem) { return (elem % 2 == 1); });

  return 0;
}
