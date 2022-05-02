#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{

  BSTree *t = new BSTree();
  t->setup();

  std::cout <<  t->get_debug_string() << "\n";
  int v = 15;

  
  try {
    int x  = t->search(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";
    
  }
  try {
    int x  = t->searchr(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";
    
  }

  t->insert(22);
  std::cout <<  t->get_debug_string() << "\n";
  t->insert(3);
  std::cout <<  t->get_debug_string() << "\n";

  std::cout << t->treesum() << "\n";

  
  return 0;
}

