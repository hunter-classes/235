#include <iostream>
#include "List.h"

int main()
{
  List *l = new List();
  std::cout << l->getDebugString();
  l->insert("one");
  l->insert("two");
  l->insert("three");
  l->insert("four");
  std::cout << l->getDebugString();

  l->push_back("a");
  l->push_back("b");
  l->push_back("c");
  std::cout << l->getDebugString();
  std::cout << l->size() << "\n";
  std::cout << l->getDebugString();
  l->remove(2);
  std::cout << l->getDebugString();
  (*l)[2]="ZOWIE";
  std::cout << l->getDebugString();



  List l2;
  l2.insert("a");
  l2.insert("b");
  l2.insert("c");
  l2.insert("d");
  l2.insert("e");
  l2.insert("f");

  
  std::cout << l2.getDebugString();
  std::cout << l2[2] <<"\n";
  l2[2]="TEST";
  std::cout << l2.getDebugString();
  delete l;
  return 0;
}
