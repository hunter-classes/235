#include <iostream>
#include <unistd.h>

#include "stack.h"

int main()
{
  stack *s = new stack();
  std::cout << s->is_empty() << "\n";

  try {
    s->push(5);
  } catch (int e){
    std::cout << "stack full\n";
  }
  try {
    s->push(10);
  } catch (int e){
    std::cout << "stack full\n";
  }
  try {
    s->push(15);
  } catch (int e){
    std::cout << "stack full\n";
  }


  std::cout << s->is_empty() << "\n";
  std::cout << s->top() << "\n";
  int val;
  try {
    val = s->pop();
    std::cout << val << " " << s->top() << "\n";
  } catch (int e){
    std::cout << "Stack empty\n";
  }
  try {
    val = s->pop();
    std::cout << val << " " << s->top() << "\n";
  } catch (int e){
    std::cout << "Stack empty\n";
  }
  try {
    val = s->pop();
    std::cout << val << " " << s->top() << "\n";
  } catch (int e){
    std::cout << "Stack empty\n";
  }
  
  
  return 0;
}
