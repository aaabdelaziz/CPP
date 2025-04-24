
std::transform(myList.begin(), myList.end(), myList.begin(), [](int element) {
  // Transform each element using a function
  return element * 2;
});
