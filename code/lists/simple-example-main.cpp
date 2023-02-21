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

  Node *tmp;
  // point tmp to n1
  // and add the code to print out the contents
  // of the entire list
  // Hint: think of using a loop
  
  

  return 0;
}
