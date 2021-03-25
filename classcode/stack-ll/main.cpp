#include <iostream>
#include "stack.h"
int main()
{
  stack *s = new stack();

  std::cout << s->is_empty() << "\n";
  s->push(5);
  s->push(10);
  s->push(20);
  std::cout << s->is_empty() << "\n";
  int r = s->pop();


  std::cout << s->is_empty() << " " << r << "\n";
  r = s->pop();
  std::cout << s->is_empty() << " " << r << "\n";
  r = s->pop();
  std::cout << s->is_empty() << " " << r << "\n";
  
  return 0;
}
