
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  // Sample vector of pairs
  std::vector<std::pair<int, int>> pairs = {
      {1, 5}, {3, 8}, {2, 7}, {4, 6}, {5, 5}};

  // Find the pair with the maximum sum
  auto maxSumPair = std::max_element(
      pairs.begin(), pairs.end(), [](const auto &pair1, const auto &pair2) {
        return pair1.first + pair1.second < pair2.first + pair2.second;
      });

  // Check if the vector is not empty before accessing the result
  if (maxSumPair != pairs.end()) {
    std::cout << "Pair with maximum sum: {" << maxSumPair->first << ", "
              << maxSumPair->second << "}" << std::endl;
  } else {
    std::cout << "Vector is empty." << std::endl;
  }

  return 0;
}
