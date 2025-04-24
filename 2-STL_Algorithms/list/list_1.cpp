
#include <iostream>
#include <list>

int main() {
  std::list<int> myList;

  // Insert elements at the back
  myList.push_back(10);
  myList.push_back(20);
  myList.push_back(30);

  // Insert elements at the front
  myList.push_front(5);

  // Insert an element after the first element
  auto it = myList.begin();
  ++it;
  myList.insert(it, 15);

  // Print elements using iterators
  for (const auto &element : myList) {
    std::cout << element << " ";
  }
  std::cout << std::endl;

  return 0;
}
