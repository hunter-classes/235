#pragma once

#include "Node.h"

class List{
 private: Node *head;

 public:
  List();
  // ~List();

  void insert(std::string data);

  std::string get(int loc);

  int length();

  std::string toString(); // for testing and debugging
  
};
