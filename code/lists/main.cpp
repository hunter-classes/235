#include <iostream>
#include "List.h"

int main()
{
  List *l = new List();
  l->insert("one");
  std::cout << l->toString() << "\n";

  l->insert("two");
  std::cout << l->toString() << "\n";
  l->insert("three");
  std::cout << l->toString() << "\n";
  l->insert("four");
  std::cout << l->toString() << "\n";
  return 0;
}
