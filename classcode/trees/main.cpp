#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{

  BSTree *t = new BSTree();
  t->setup();
  std::cout << t->get_debug_string() << "\n";
  return 0;
}
