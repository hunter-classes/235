#include <iostream>
#include "List.h"


int main()
{
  List *l = new List();
  std::cout << l->toString() << "\n";
  l->insert("Hello");
  std::cout << l->toString() << "\n";
  l->insert("world");
  std::cout << l->toString() << "\n";
  l->insert("!");
  std::cout << l->toString() << "\n";

  std::string result;
  int i = 2;
  result = l->get(i);
  std::cout << "l["<<i<<"] = " << result << "\n";

  std::cout << l->length() << "\n";
  l->insert("Stuf");
  std::cout << l->length() << "\n";
  return 0;
}
