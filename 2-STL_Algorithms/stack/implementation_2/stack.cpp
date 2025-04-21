#include <iostream>
#include <stack>
using namespace std;

//function to display stack
void displayStack(stack<int> s)
{
 int n = s.size();

  for(int i=0; i<n;i++)
 {
  cout<<s.top()<<" ";
  s.pop();
 }
 cout<<"\n";

 }

// Main function
int main()
{
  stack<int> s;

   //push - inserting elements 1,2 & 3 in stack
  s.push(1);
  s.push(2);
  s.push(3);

   //display the stack
  cout<<"Elements of Stack are : ";
  displayStack(s);

   //pop - deleting the element at top
  s.pop();

   cout<<"Stack after pop operation is : ";
  displayStack(s);

   //Display element at top
  cout<<"Element at top is : "<<s.top()<<"\n";

   //to check if queue is empty or not
  cout<<"Stack is empty (1 - YES / 0 - NO) : "<<s.empty()<<"\n";

   //Size of stack
  cout<<"Size of stack is : "<<s.size()<<"\n";

   return 0;
}
