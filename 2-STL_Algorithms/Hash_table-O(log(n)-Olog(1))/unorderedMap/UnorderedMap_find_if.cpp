#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>


using namespace std;

int main() {
  std::unordered_map<int, std::string> myMap;

  // if used std::string, you should include string, otherwise it will give this error 
  /*
    pair.h:72:9: error: implicit instantiation of undefined template 'std::basic_string<char>'
    _T2 second;
    */



  /********** To insert method 1 *******/
  cout << "---------------------- Insert -------------------" << endl;

  myMap.insert(make_pair(1, "One"));
  myMap.insert(make_pair(2, "Two"));
  myMap.insert(make_pair(3, "Three"));
  
  /********** To insert method 2 *******/
  
  // std::unordered_map<int, std::string> myMap = { {1, "One"},{2, "Two"}};

  /********** To Access HashMap by key *******/
  cout << "---------------------- Access -------------------" << endl;
  cout << myMap[0] << endl;
  cout << myMap[1] << endl;
  cout << myMap[2] << endl;


  /********* To iterate ***************/
  cout << "---------------------- Iterate -------------------" << endl;
  for(const auto& it : myMap){
    cout << " Key "<< it.first << " value " << it.second << endl;
  }

  /********* To Update ***************/
  cout << "---------------------- update -------------------" << endl;
  myMap[1] = "OneOne";
  for(const auto& it : myMap){
    cout << " Key "<< it.first << " value " << it.second << endl;
  }



  /********* To Find ***************/
  cout << "---------------------- Find -------------------" << endl;
  std::pair<const int, std::string> searchValue = std::make_pair(2, "Two");

  auto it = std::find(myMap.begin(), myMap.end(), searchValue);
  if (it != myMap.end()) {
    // Element found
    std::cout << "element is found" << " Key " << it->first << " value " << it->second << endl;
  }
  else
  {
        std::cout << "element not found";
  }


  /********* To Find ***************/
  cout << "---------------------- Find by index -------------------" << endl;
  auto it2 =  myMap.find(3);
  //  myMap.end() returns the position of last element+1 
  if ( it2 != myMap.end()) { 
    // Element found
    std::cout << "element is found" << " Key " << it2->first << " value " << it2->second << endl;
  }
  else
  {
        std::cout << "element not found";
  }



 
  // auto it = std::find(myMap.begin(), myMap.end(), "Three");
  // if (it != myMap.end())
  //     std::cout << "Found with key " << search->first << ' value ' << search->second << '\n';
  // else
  //     std::cout << "Not found\n";

  return 0;
}
