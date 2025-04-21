#include <iostream>
#include <string>

using namespace std;

void CompareStrings(const string& str1, const string& str2){


  /* Method 1 */
  int result = str1.compare(str2);
  if (result == 0) {
      std::cout << "Strings are equal" << std::endl;
  } else if (result < 0) {
      std::cout << "First string is less than second string" << std::endl;
  } else {
      std::cout << "First string is greater than second string" << std::endl;
  }

  /* // Method 2 
  std::string str1 = "hello";
  std::string str2 = "world";
  
  if (str1 == str2) {
      std::cout << "Strings are equal" << std::endl;
  } else {
      std::cout << "Strings are not equal" << std::endl;
  }
  */

}
int main() {
    std::string s1 = "hello";
    std::string s2 = "world";
    
    CompareStrings(s1,s2);

    s1 = "hello";
    s2 = "hello";
    
    CompareStrings(s1,s2);



    
    return 0;
}
