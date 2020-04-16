#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{

  BSTree *t = new BSTree();
  t->setup();
  std::cout << t->get_debug_string() << "\n";
  std::cout << "\n\n";

  try {
    std::cout << t->search(100) << "\n";
  } catch (int e){
    std::cout << "Not found\n";
  }
  std::cout << t->search(10) << "\n";
  std::cout << t->search(20) << "\n";
  return 0;
}
