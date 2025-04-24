#include <algorithm>
#include <iostream>
#include <vector>

/*

https://www.youtube.com/watch?v=tcYGbDd1hOg&t=1240s
https://www.youtube.com/watch?v=mWgmBBz0y8c
https://www.youtube.com/watch?v=damrgf7GJac&list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
*/
using namespace std;

int main() {

  // 1- basic lambda expression is like this:
  // []{// SOme logic here} ();
  // [capture_list](parameters list_optiona){ impelementation} () --> to call
  // the lambda and execute it
  [] { std::cout << "lambda execution"; }();

    //2- 

  return 0;
}
