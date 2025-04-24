#include <algorithm>
#include <iostream>
#include <unordered_map>

void printKeyValue(const std::pair<int, std::string> &keyValue) {
  std::cout << "Key: " << keyValue.first << ", Value: " << keyValue.second
            << std::endl;
}

int main() {
  std::unordered_map<int, std::string> myMap = {
      {1, "One"}, {2, "Two"}, {3, "Three"}};

  std::for_each(myMap.begin(), myMap.end(), printKeyValue);

  return 0;
}
