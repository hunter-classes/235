#include <iostream>
#include <unistd.h>

#include "stack.h"

int main()
{
  stack *s = new stack();
  std::cout << s->is_empty() << "\n";

  try{
    s->push(5);
  } catch (int e){
    std::cout << "You tried to push and the stack is full\n";
  }
  try{
    s->push(5);
  } catch (int e){
    std::cout << "You tried to push and the stack is full\n";
  }
  try{
    s->push(5);
  } catch (int e){
    std::cout << "You tried to push and the stack is full\n";
  }
  try{
    s->push(5);
  } catch (int e){
    std::cout << "You tried to push and the stack is full\n";
  }
  try{
    s->push(5);
  } catch (int e){
    std::cout << "You tried to push and the stack is full\n";
  }
  try{
    s->push(5);
  } catch (int e){
    std::cout << "You tried to push and the stack is full\n";
    std::cout << "Error code: " << e << "\n";
  }
  
  std::cout << s->is_empty() << "\n";
  std::cout << s->top() << "\n";

  int val = s->pop();
  std::cout << val << " " << s->top() << "\n";
  try{
    // this is bad practice - we shouldn't have so many
    // different lines in here that can end up with an
    // exception - this is just for demo purposes
    val = s->pop();
    val = s->pop();
    val = s->pop();
    val = s->pop();
    val = s->pop();
  } catch (int e){
    std::cout << "Tried to pop when empty, code: " << e << "\n";
  }
  std::cout << val << " " << s->top() << "\n";
  return 0;
}
