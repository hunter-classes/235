#pragma once

#include "Node.h"

class List{
 private:
  Node *head;
  
 public:
  List();
  ~List();
  
  void insert(std::string data);
  std::string get(int loc);
  void insert(int loc, std::string data);
  void remove(int loc);
 
  std::string toString();
  
};
