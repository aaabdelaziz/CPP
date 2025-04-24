
#include <iostream>
#include <string>

#include <memory>

class Entity {

public:
  Entity() { std::cout << "create an Entity" << std::endl; }
  ~Entity() { std::cout << "Destory an Entity" << std::endl; }
  void print() { std::cout << "just print" << std::endl; }
};

/*Unique- Shared - weak - move */
int main() {

  // entity is a unique pointer of type Entity;
  // new Entity() to create a n object from Entity type in heap and return address to the pointer
  std::unique_ptr<Entity> entity(new Entity());
  entity->print();

  // the unique pointer will automatically call the desctructor and free the
  // pointer in heap 

  // we cant copy a unique pointer to another0

  return 0;
}

structure node{
  std::unique_ptr<node > net;

};