
// CPP program to demonstrate working of map
#include <iostream>
#include <map>

using namespace std;

int main() {

  map<int, int> m;

  // There are three ways to insert in map
  m[1] = 2; // Insertion by indexing

  // Direct pair insertion
  m.insert({4, 5});

  // Insertion of pair by make_pair
  m.insert(make_pair(8, 5));

  cout << "Elements in map:\n";
  for (auto it : m)
    cout << "[ " << it.first << ", " << it.second << "]\n"; // Sorted

  return 0;
}
