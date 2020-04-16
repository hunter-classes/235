#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{

  BSTree *t = new BSTree();

  t->insert(10);
  t->insert(5);
  t->insert(15);

  std::cout <<  t->get_debug_string() << "\n";

  t->insert(3);
  t->insert(20);
  std::cout <<  t->get_debug_string() << "\n";

  /*
    try {
    std::cout << t->search(100) << "\n";
    } catch (int e){
    std::cout << "Not found\n";
    }
    std::cout << t->search(10) << "\n";
    std::cout << t->search(20) << "\n";

    try {
    std::cout << t->searchr(100) << "\n";
    } catch (int e){
    std::cout << "Not found\n";
    }
    std::cout << t->searchr(10) << "\n";
  std::cout << t->searchr(20) << "\n";

  std::cout << t->get_debug_string() << "\n";
  */
  return 0;
}
