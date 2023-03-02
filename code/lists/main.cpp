#include <iostream>
#include "List.h"

int main()
{
  List *l = new List();
  std::cout << l->toString() << " " << l->length() << "\n";
  l->insert(0,"a");
  std::cout << l->toString() << " " << l->length() << "\n";
  l->insert(0,"b");
  l->insert(0,"c");
  l->insert(0,"d");
  try {
    l->insert(10,"x");
  } catch (std::exception e){
    std::cout << "Insert x didn't work\n";
  }
  std::cout << l->toString() << "\n";
  l->insert(2,"inserted at 2");
  std::cout << l->toString() << "\n";
  l->insert(5,"inserted at end");
  std::cout << l->toString() << " " << l->length() << "\n";

  std::cout << l->find("b") << "\n";
  std::cout << l->find("d") << "\n";
  std::cout << l->find("blinserted at end") << "\n";

  std::cout << l->toString() << " " << l->length() << "\n";
  l->remove(0);
  std::cout << l->toString() << " " << l->length() << "\n";
  l->remove(4);
  std::cout << l->toString() << " " << l->length() << "\n";
  try {
    l->remove(24);
    std::cout << l->toString() << " " << l->length() << "\n";
  } catch (std::exception e){
    std::cout << "Tried to remove past the end\n";
  }
  
  delete l;


  return 0;
}
