#pragma once
#include <iostream>
#include "Node.h"

#define STACK_ERR_EMPTY 1
#define STACK_ERR_FULL 2
#define STACK_ERR_OTHER 4


class stack{
private:
  Node *head;
  
public:
  stack();
  ~stack();
  void push(int); // add an item to the top of the stack
  int pop(); // remove and return an item from the top of the stack
  int top();
  bool is_empty(); // return true if the stack is empty;
};
