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


  std::cout << "Trying to pop an empty stack\n";
  try {
    r = s->pop();
    std::cout << "We got " << r << "\n";
  } catch (int e){
    std::cout << "We got exception number: " << e << "\n";
  }
  std::cout << "And the program continues\n";
  return 0;
}
