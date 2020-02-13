#include <iostream>
#include "List.h"
int main()
{
  List *l = new List();

  l->insert("one");
  l->insert("two");
  l->insert("three");
   l->insert("four");

   std::cout << l->length() << " items in the list.\n";
   std::cout << l->getDebugString() << "\n";

    l->insert("five");
   l->insert("six");
   l->insert("seven");

   std::cout << l->length() << " items in the list.\n";
   std::cout << l->getDebugString() << "\n";

   delete l;
   std::cout << "The end\n";
   return 0;
}
