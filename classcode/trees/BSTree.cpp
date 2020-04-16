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
  // insert new nodes as a leaf

  Node *n = new Node(d);

  if (root==nullptr){
    root = n;
    return;
    }

  // search for the insertion point
  Node *t = root;
  Node *t2;
  while (t != nullptr){
    t2 = t;
    
    if (t->getData() < d)
      t = t->getRight();
    else
      t = t->getLeft();
  }
  // Now, t is at null but t2 is at the node we want to link from.
  if (d < t2->getData())
    t2->setLeft(n);
  else
    t2->setRight(n);
  
}
std::string BSTree::gds_helper(Node *n){
  if (n==nullptr){
    return "";
  } else {
    return std::to_string(n->getData()) + " - " +
      gds_helper(n->getLeft()) +
      gds_helper(n->getRight());
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


int BSTree::searchr(Node *n, int value){
  if (n==nullptr)
    throw -1;

  if (n->getData()==value)
	return value;
      else if (n->getData() > value)
	return this->searchr(n->getLeft(),value);
      else return this->searchr(n->getRight(),value);


  return 0;
  
}

int BSTree::searchr(int value){
  int r=  this->searchr(root,  value);

  return r;
}
