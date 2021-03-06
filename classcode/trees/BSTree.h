#pragma once
#include <stdio.h>

class BSTree{
 private:
  Node *root;

 public:
  BSTree();


  std::string get_debug_string();
  std::string traverse(Node *n);
  int search(int value);
  void insert(int value);

  int treesum();
  int treesum(Node *n);
  int searchr(int value);
  int searchr(int value, Node *n);
  void setup();
  
};
