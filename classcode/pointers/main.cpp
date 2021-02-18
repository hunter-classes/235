#include <iostream>

#include "Node.h"

int main(int argc, char *argv[])
{
  Node *n1 = new Node("abc");
  Node *n2 = new Node("xyz");
  n1->setNext(n2);
  n2->setNext(n1);
  std::cout << n1->getData() << "\n";
  std::cout << n1->getNext()->getData() << "\n";
  std::cout << n1->getNext()->getNext()->getData() << "\n";
  return 0;
}
