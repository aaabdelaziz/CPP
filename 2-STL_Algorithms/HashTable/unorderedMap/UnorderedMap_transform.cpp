#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

std::string addPrefix(const std::pair<int, std::string> &keyValue) {
  return "Prefixed_" + keyValue.second;
}

int main() {
  std::unordered_map<int, std::string> myMap = {
      {1, "One"}, {2, "Two"}, {3, "Three"}};

  std::vector<std::string> prefixedValues;
  std::transform(myMap.begin(), myMap.end(), std::back_inserter(prefixedValues),
                 addPrefix);

  return 0;
}
