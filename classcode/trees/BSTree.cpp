#include <iostream>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree(){
  root = nullptr;
}

std::string BSTree::gds_helper(Node *n){
  std::string a,b,c;
  
  if (n==nullptr){
    return "";
  } else {

    /*
      1. recursively process the left subtree
      2. Process the current node
      3. recursively process the right subtree

      This will traverse a BSTree in sorted order.

    */
    
      a =  gds_helper(n->getLeft());
      b = std::to_string(n->getData());
      c =  gds_helper(n->getRight());


    return a + ", " + b+ ", " + c;

     
  }
};

std::string BSTree::get_debug_string(){
  return gds_helper(root);
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

