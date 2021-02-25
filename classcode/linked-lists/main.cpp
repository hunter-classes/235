#include <iostream>

#include "List.h"
int main(int argc, char *argv[])
{

  List *l1 = new List();
  std::cout << l1->toString() << "\n";

  l1->insert("a");
  l1->insert("b");
  l1->insert("c");
  l1->insert("d");
  l1->insert("e");
  std::cout << l1->toString() << "\n";

  std::cout << l1->get(2) << " " << l1->get(5) << "\n";
  return 0;

}
