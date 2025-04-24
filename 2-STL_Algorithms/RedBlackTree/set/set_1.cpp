#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {

  set<int> set_values;
  set_values.insert(2);
  set_values.insert(4);
  set_values.insert(5);

  cout << "Elements in set:\n";
  for (const auto &item : set_values)
    cout << item << endl;

  return 0;
}
