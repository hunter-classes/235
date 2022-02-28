#include <iostream>
#include "List.h"


int main()
{
  List *l = new List();

  l->insert("zero");
  l->insert("one");
  l->insert("two");
  l->insert("three");
  l->insert("four");

  std::cout << l->toString() << "\n";
  l->insert(3,"HellO");
  std::cout << l->toString() << "\n";
  l->insert(3,"World");
  std::cout << l->toString() << "\n";
  l->insert(0,"HellO");
  std::cout << l->toString() << "\n";
  l->insert(0,"front");
  std::cout << l->toString() << "\n";

  l->remove(1);
  std::cout << l->toString() << "\n";
  delete l;
  return 0;
}
