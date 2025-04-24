#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<int> mySet;

  // Insert elements
  mySet.insert(42);
  mySet.insert(15);
  mySet.insert(7);

  // Check if an element is present
  if (mySet.find(15) != mySet.end()) {
    std::cout << "Element 15 is present in the set." << std::endl;
  }

  // Iterate over elements
  for (const auto &element : mySet) {
    std::cout << element << " ";
  }
  std::cout << std::endl;

  return 0;
}
