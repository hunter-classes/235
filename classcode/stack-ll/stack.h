#pragma once
#include <iostream>
#include "Node.h"

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
