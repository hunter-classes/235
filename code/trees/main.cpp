#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{

  BSTree *t = new BSTree();
  t->setup();

  std::cout <<  t->get_debug_string() << "\n";
  int v = 15;

  int n;
  n = t->search(10);
  std::cout << "found " << n << "\n";
  n = t->search(8);
  std::cout << "found " << n << "\n";
  n = t->search(15);
  std::cout << "found " << n << "\n";
  try {
  n = t->search(17);
  std::cout << "found " << n << "\n";
  } catch (int e){
    std::cout << 17 << " not found\n";
  }

  t->insert(17);
  
  n = t->search(17);
  std::cout << "found " << n << "\n";

  std::cout << t->get_debug_string() << "\n";
  return 0;
}

