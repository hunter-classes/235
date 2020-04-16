#pragma once
#include <stdio.h>

class BSTree{
 private:
  Node *root;

 public:
  BSTree();
  void insert(int d);
  std::string get_debug_string();
  std::string gds_helper(Node *n);
  void setup();
  int search(int value);
  int searchr(int value);
  int searchr(Node *n, int value);
  
};
