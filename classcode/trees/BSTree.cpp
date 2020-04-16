#include <iostream>
#include "Node.h"
#include "BSTree.h"

// Binary Search Tree
// Binary tree - every node has 0 1 or 2 children
// Given a node N
// every node in N's left subtree has a value < the value in N
// every node in N's right subtree has a value > the value in N

BSTree::BSTree(){
  root = nullptr;
}

void BSTree::insert(int d){
  
}
std::string BSTree::get_debug_string(){

  if (root == nullptr){
    return "";
  } else {
    Node *n = root;
    std::string s = std::to_string( n->getData()) + " " + std::to_string(n->getLeft()->getData()) + " " + std::to_string(n->getRight()->getData());

    n = root->getRight();
    s = s + "\n" + std::to_string( n->getData()) + " " + std::to_string(n->getLeft()->getData()) + " " + std::to_string(n->getRight()->getData());
    return s;
  }
};
void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(25);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(7);
  n2->setLeft(n);
  
}
  
int BSTree::search(int value){
  Node *t = root;

  while (t != nullptr){
    if (t->getData()==value)
      return value;
    else if (t->getData() > value)
      t = t->getLeft();
    else
      t = t->getRight();
   }
  throw -1;
  return 0;
}

