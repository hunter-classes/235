#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{

  BSTree *t = new BSTree();
  t->setup();

  std::cout <<  t->get_debug_string() << "\n";
  int v = 13;
  try {
    int x  = t->search(v);
    std::cout << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";
    
  }
  return 0;
}
