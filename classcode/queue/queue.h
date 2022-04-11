#pragma once
#include <iostream>
#include "Node.h"

#define QUEUE_ERR_EMPTY 1
#define QUEUE_ERR_FULL 2
#define QUEUE_ERR_OTHER 4

class queue{
 private:
  Node *head, *tail;
  //     node1-->node2-->node3-->null
  // head--^                ^-----------tail

 public:
  queue();
  void enqueue(int);
  int dequeue();

  int front();
  std::string get_debug_string();
  
};



