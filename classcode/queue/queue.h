#pragma once
#include <iostream>
#include "Node.h"

#define QUEUE_ERR_EMPTY 1
#define QUEUE_ERR_FULL 2
#define QUEUE_ERR_OTHER 4

class queue{
private:
  Node *head, *tail;
  //       node1-->node2-->node3-->null
  // head---^                  ^--------tail
  
public:
  queue();
  void enqueue(int);
  int dequeue();
  
  std::string get_debug_string();
  
  
  /*
   
    stack();
    ~stack();
  void push(int); // add an item to the top of the stack
  int pop(); // remove and return an item from the top of the stack
  int top();
  bool is_empty(); // return true if the stack is empty;
  */
};
