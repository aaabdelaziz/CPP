
#include <iostream>
#include <vector>

class Node {

public:
  std::string key;
  int value;
  Node *nextptr;

  Node(std::string key, int value) {
    this->key = key;
    this->value = value;
    nextptr = nullptr;
  }
};

class hashTable {

private:
  static const int SIZE = 7;
  Node *table[SIZE];

  int hash(std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      // get ascii code for each char in the key
      int ascii_val = int(key[i]);
      // calculate the index for key, based on it's characters
      // the index will be value between 0 - (size-1)
      hash = (hash + ascii_val * 23) % SIZE;
    }
    return hash;
  }

public:
  hashTable() {
    for (int i = 0; i < SIZE; i++) {
      table[i] = nullptr;
    }
  }

  ~hashTable() {
    std::cout << "\nunallocate all locations for each bucket in hash table\n";
    for (int i = 0; i < SIZE; i++) {
      Node *head = table[i];
      Node *temp = head;
      while (head) {
        head = head->nextptr;
        delete temp;
        temp = head;
      }
    }
  }

  void set(std::string key, int value) {
    int index = hash(key);
    Node *newNode = new Node(key, value);
    // we need to know if we have a node at that address in HashTable
    if (table[index] ==
        nullptr) { // If no node, it means it's first time to insert
      table[index] = newNode;
    } else {
      Node *temp = table[index];
      while (temp->nextptr != nullptr) {
        // Loop till reaching to the last node in linked list
        temp = temp->nextptr;
      }
      temp->nextptr = newNode;
    }
  }

  int get(std::string key) {
    int index = hash(key);
    Node *temp = table[index];
    // if the table index is not empty
    while (temp) {
      if (temp->key == key)
        return temp->value;
      // else it will return this
      temp = temp->nextptr;
    }
    return -1;
  }

  void printTable() {
    for (int i = 0; i < SIZE; i++) {
      std::cout << i << ": " << std::endl;
      // if the table element isn't nullptr (not empty)
      if (table[i]) {
        Node *temp = table[i];
        while (temp) {
          std::cout << "{ Key: " << temp->key << ", Value: " << temp->value
                    << "} ";
          temp = temp->nextptr;
        }
        std::cout << std::endl;
      }
    }
  }

  std::vector<std::string> printAllKeys() {
    std::vector<std::string> all_keys;
    for (int i = 0; i < SIZE; i++) {
      Node *temp = table[i];
      while (temp) {
        all_keys.push_back(temp->key);
        temp = temp->nextptr;
      };
    }
    return all_keys;
  }
};

// class PairSum{
//     std::vector<int,int> array;
//     public:
// }

int main() {

  hashTable *table = new hashTable();

  // set three key, value pairs
  table->set("nails", 100);
  table->set("tile", 100);
  table->set("lumbs", 100);
  table->printTable();
  std::cout << "the hash value of"
            << " nails is: " << table->get("nails") << std::endl;

  std::cout << "\n-------- All Keys values are --------\n";
  auto all_keys = table->printAllKeys();
  for (auto key : all_keys)
    std::cout << key << " ";

  // std::cout << "Finding pairs with equal sum" << std::endl;
  // int sum = 9;
  // int arr []= {2,3,1,4,3,7,4,9,8};

  // for (int it = 0; it < sizeof(arr)/sizeof(int); it++){
  //     std::cout << arr[it];
  // }

  // unallocate resources
  delete table;

  return 0;
}
