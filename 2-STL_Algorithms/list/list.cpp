#include <algorithm>
#include <iostream>
#include <list>


using namespace std;

int main() {
  // ordered list
  list<int> mylist;
  
  /****************************** To Insert  (push_front, push_back)  ****************************/

  mylist.push_front(2);
  mylist.push_front(5);
  mylist.push_front(24);
  
  for (const auto& it : mylist)
    cout << it << " - " ;
  cout << endl;

  mylist.push_back(7);

  for (const auto& it : mylist)
    cout << it << " - " ;
  cout << endl;

  mylist.push_front(1);
  for (const auto& it : mylist)
    cout << it << " - " ;
  cout << endl;

  /****************************** To find and insert after value ****************************/

  // To find value 2 in the list and get the index in the iterator
  list<int>::iterator itr1 = find(mylist.begin(), mylist.end(),2);
  // it will insert 30 before 2    --->   1 - 24 - 5 - (30 - 2) - 7 - 
  mylist.insert(itr1, 30);  
  for (const auto& it : mylist)
    cout << it << " - ";
  cout << endl;


  // To find value  24 in the list and get the index in the iterator
  list<int>::iterator itr2 = find(mylist.begin(), mylist.end(),24);
  // it will insert 22 before 24    ---> 1 - (22 - 24) - 5 - 30 - 2 - 7 - 
  mylist.insert(itr2, 22);  

  for (const auto& it : mylist)
    cout << it << " - ";
  cout << endl;

    // To find value 0 in the list and get the index in the iterator
  list<int>::iterator itr3 = find(mylist.begin(), mylist.end(),0);
  // it will insert 33 before value 0, but since no value 0 in the list, it will insert 33 at the end    ------> 1 - 22 - 24 - 5 - 30 - 2 - 7 - 33 
  mylist.insert(itr3, 33);  

  for (const auto& it : mylist)
    cout << it << " - ";
  cout << endl;

  /****************************** To delete (pop_back, pop_front) ****************************/

  mylist.pop_back();  
  for (const auto& it : mylist)
    cout << it << " - ";
  cout << endl;

  mylist.pop_front();  
  for (const auto& it : mylist)
    cout << it << " - ";
  cout << endl;

  /************** to find element *************/
  int elem_to_find = 30;

  auto itr = std::find(mylist.begin(), mylist.end(), elem_to_find);
   if (itr != mylist.end()) {
        std::cout << "Element " << to_string(elem_to_find) << " found at position " << std::distance(mylist.begin(), itr) << std::endl;
    } else {
        std::cout << "Element " << to_string(elem_to_find) <<"not found" << std::endl;
    }

  /**
   * @brief
   * 
   * 
   * 
   * Insertion/Deletion at Specific Position: 
    To insert (insert) or erase (erase) an element at a specific position in the list:
    Traverse the list to find the position.
    Create or delete the node at the specified position.
    Update pointers to link neighboring nodes appropriately.
    
    Search:
    To search for an element in the list:
    Traverse the list, starting from the head or tail, depending on the direction of search.
    Compare each element with the target value until a match is found or the end of the list is reached.
    
    Traversal:
    To iterate over all elements in the list:
    Start at the head or tail node.
    Follow the next (or previous) pointers to visit each node in sequence until reaching the end of the list.

    Sorting:
    To sort the elements of the list:
    Use a sorting algorithm such as merge sort or quicksort, adapted to work with linked lists.
    Update pointers to reorder the nodes accordingly.
   
    Merging:
    To merge two sorted lists into a single sorted list:
    Iterate over both lists simultaneously, comparing elements and selecting the smaller (or larger) one.
    Construct a new list by linking the selected elements in the correct order.

   * 
   */

  return 0;
}
