#include <iostream>

#include "Node.h"

int main(int argc, char *argv[])
{
  Node *p1 = new Node();
  p1->setData("hello"); 

  Node *p2 = new Node("World");

  p1->setNext(p2);

  std::cout << p1->getData() << "\n";
  std::cout << p2->getData() << "\n";
  std::cout << p1->getNext()->getData() << "\n";

  p2 = new Node("!");

  p1->getNext()->setNext(p2);
  
  std::cout << p1->getData() << "\n";
  std::cout << p1->getNext()->getData() << "\n";
  std::cout << p1->getNext()->getNext()->getData() << "\n";

  Node *walker = p1;
  std::cout << walker->getData() << "\n";

  walker =  walker->getNext(); //   walker =  p1->getNext();
  std::cout << walker->getData() << "\n";

  walker =  walker->getNext(); //   walker =  p1->getNext();
  std::cout << walker->getData() << "\n";
  
  walker = p1;
  while (walker != nullptr){
    std::cout << walker->getData() << "\n";
    walker =  walker->getNext(); //   walker =  p1->getNext();
  }

  // at this point walker points to (refers to) nullptr
  // and if we try to dereference it, we get a segfault
  //    std::cout << walker->getData() << "\n";

  
  return 0;

}
