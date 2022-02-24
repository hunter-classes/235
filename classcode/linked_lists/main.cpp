#include <cstdio>
#include <iostream>
#include "Node.h"

int main()
{
  Node *n1;
  Node *n2;

  n1 = new Node("Hello");
  n2 = new Node("World");

  std::cout << n1->getData() << "\n";
  std::cout << n2->getData() << "\n";

  n1->setNext(n2);
  std::cout << n1->getNext() << "\n";
  std::cout << n2 << "\n";
  std::cout << n1->getNext()->getData() << "\n";

  n2->setNext(new Node("!"));

  std::cout << n1->getNext()->getNext()->getData() << "\n";

  Node *walker;
  walker = n1;
  while (walker != nullptr){
    std::cout << walker->getData() << " ";
    walker = walker->getNext();
  }
  std::cout << "\n\n";
  return 0;
}


