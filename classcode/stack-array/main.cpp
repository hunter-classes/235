#include <iostream>
#include <unistd.h>

#include "stack.h"

int main()
{
  stack *s = new stack();
  std::cout << s->is_empty() << "\n";

  s->push(5);
  s->push(10);
  s->push(15);

  std::cout << s->is_empty() << "\n";
  std::cout << s->top() << "\n";

  int val = s->pop();
  std::cout << val << " " << s->top() << "\n";
  
  return 0;
}
