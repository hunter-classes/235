#include <iostream>

#include "Node.h"

int main()
{
  Node *n1;
  Node *n2;

  n1 = new Node("Hello");
  n2 = new Node("World");

  n1->setNext(n2);
  
  
  std::cout << n1->getData()<<"\n";
  std::cout << n2->getData()<<"\n";
  std::cout << n1->getNext()->getData()<<"\n";
  return 0;
}
