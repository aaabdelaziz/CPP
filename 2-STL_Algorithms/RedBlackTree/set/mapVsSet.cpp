
#include <iostream>
#include <map>
#include <set>

int main() {
  // Example 1: std::set
  std::cout << "Example 1: std::set" << std::endl;
  std::set<int> mySet;

  // Insert elements into the set
  mySet.insert(3);
  mySet.insert(1);
  mySet.insert(4);
  mySet.insert(2);
  mySet.insert(3); // Duplicate elements are ignored

  // Print elements of the set
  for (const auto &element : mySet) {
    std::cout << element << " ";
  }
  std::cout << std::endl << std::endl;

  // Example 2: std::map
  std::cout << "Example 2: std::map" << std::endl;
  std::map<int, std::string> myMap;

  // Insert key-value pairs into the map
  myMap[1] = "One";
  myMap[3] = "Three";
  myMap[2] = "Two";
  myMap[4] = "Four";
  myMap[3] = "New Three"; // Updating value for an existing key

  // Print key-value pairs in the map
  for (const auto &pair : myMap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  return 0;
}
