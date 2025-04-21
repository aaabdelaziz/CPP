/**********************************************************************************
 * Items in linked list are distributed in different locations in memory
 * instead of being in contiguous locations.
 *
 * Items are Nodes
 * each Node has a pointer next that point to next Node
 *
 * Inserting/deleting a Node at beginning or end of linked list is O(1).
 *
 * Inserting/deleting a Node at middle or at some position index of linked list
 * is O(n).
 *************************************************************************************/

#include <iostream>

using namespace std;

/*******************************************
 * Node class with
 *
 * attributes:
 *      id          Node index
 *      value       value in the Node
 *
 * methods:
 *      Node    is a constructor
 *
 *******************************************/
class Node {

public:
  int id;
  int value;
  Node *next;

  Node(int id, int value) 
  {

    this->value = value;
    this->id = id;
    next = nullptr;
  }
  ~Node() {}
};

/*******************************************
 * LinkedList class with methods
 * Append, Preappend, delete, insert, find
 *******************************************/
class LinkedList {

  Node *head;
  Node *tail;
  int length;

public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
  }
  LinkedList(int id, int value) {
    cout << " Creating First Node with value " << value << endl;
    // create a new Node
    head = new Node(id, value);
    tail = head;
    length = 1;
  }

  LinkedList &operator=(const LinkedList &obj) {
    if (this != &obj) {
      // assign the obj memembers and ensure deep copy
    }
    return *this;
  }

  LinkedList(const LinkedList &obj) {
    head = obj.head;
    tail = obj.tail;
    length = obj.length;
  }

  ~LinkedList() {
    // temp point to same first Node like head
    Node *temp = head;
    // loop till the head == nullptr
    while (head) {
      // make head point to next Node
      head = head->next;
      delete temp;
      // update temp to move also to next Node like head
      temp = head;
    }
  }

  void append(int value) {
    // create a new Node with value
    cout << " Appending to end of LL with Value: " << value << endl;
    // if no node exist
    if(length == 0){
      // insert first Node at the end of LL
      tail->next = new Node((head->id) + 1, value);
      head->next = tail->next;
    }
    else
    {
      // append the new node
      tail->next = new Node( (tail->id)+1, value);
      // make tail also now point to last node
      tail = tail->next;
    }
    length++;
  }

  void deleteLastNode() {
    // delete last node in LinkedList and update tail
    cout << " deleting last element in LL" << endl;
    // LL is empty
    if(length == 0){
      return;
    }
    else{

      //Create temp and pre pointers to iterate over the LL
      Node* temp = head;
      Node* pre = head;

      // traverse LL till reaching the end
      while(temp->next){
        // save current temp node address to pre
        pre = temp;
        //update temp to point to next node
        temp = temp->next;
      }
      // while loop ends when reaching end of LL with values that temp points to last node and pre points to previous last node
      // make tail = pre
      tail = pre;
      // update tail pointer
      tail->next = nullptr;
      length--;
      // But here in case we already have one node in LL
      if(length == 0){
        length = 1;
      }
      if(length == 1){
        tail = nullptr;
        head = nullptr;
      }
      delete temp;

   }
  }

  void deleteNodeIndex(int index) {
    // search for the index
    //  delete that Node with that index and update LL
  }

  // void insertItem(int index, int value) {
  //   // insert at certain index in LL
  // }

  // void findItem(int index) {}

  void printLL() {
    Node *temp = head;
    while (temp) {
      cout << "Node ID: " << temp->id << " value: " << temp->value << endl;
      temp = temp->next;
    }
    cout << "total length is " << length << endl;
  }

  int getLength() { return length; }
};

int main() {

  LinkedList *ll = new LinkedList(1, 4);
  // ll->append(5);
  // ll->append(6);  
  ll->deleteLastNode();
  // ll->append(43);
  ll->printLL();

  return 0;
}
