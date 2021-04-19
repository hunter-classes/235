#pragma once
#include <stdio.h>

class BSTree{
 private:
  Node *root;

 public:
  BSTree();


  std::string get_debug_string();
  std::string gds_helper(Node *n);
  int search(int value);
  void insert(int value);

  void setup();
  
};
