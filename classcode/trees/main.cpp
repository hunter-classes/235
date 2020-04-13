#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{

  Node *n = new Node(20);
  std::cout << n->getData() << "\n";
  Node *n2 = new Node(30);
  n->setLeft(n2);
  n2 = new Node(40);
  n->setRight(n2);

  std::cout << n->getLeft()->getData() << "\n";
  std::cout << n->getRight()->getData() << "\n";

  BSTree *t = new BSTree();
  t->setup();
  std::cout << t->get_debug_string() << "\n";
  return 0;
}
