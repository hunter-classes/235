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
  return 0;
}

