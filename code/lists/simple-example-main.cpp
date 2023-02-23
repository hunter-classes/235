#include <iostream>

#include "Node.h"

int main()
{
  Node *n1;
  Node *n2;
  Node *n3;
  
  n1 = new Node("Hello");
  n2 = new Node("World");
  n1->setNext(n2);

  // n3 = new Node("middle");
  // n3->setNext(n1->getNext());
  n3 = new Node("middle",n1->getNext());
  n1->setNext(n3);
  
  n1->getNext()->getNext()->setNext(new Node("!"));
  

  
  std::cout << n1->getData()<<"\n";
  std::cout << n2->getData()<<"\n";
  std::cout << n1->getNext()->getData()<<"\n";

  std::cout << "\n----------------\n\n";
  Node *tmp;
  // point tmp to n1
  tmp = n1;
  while(tmp != nullptr){
    std::cout << tmp->getData() << "\n";
    tmp = tmp->getNext();
  }

  
  return 0;
}
