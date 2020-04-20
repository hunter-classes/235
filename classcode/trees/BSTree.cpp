#include <iostream>
#include "Node.h"
#include "BSTree.h"

// Binary Search Tree
// Binary tree - every node has 0 1 or 2 children
// Given a node N
// every node in N's left subtree has a value < the value in N
// every node in N's right subtree has a value > the value in N

// Search
// O(lgn) if balanced / full
// but it can degenerate into linear

// insertion
// O(lgn) if balanced / full
// O(n) if it is the degenerative form (linked list)

// Building a BSTree
// N*insertion time
// O(nlgn) if balanced / full
// O(n^2) if the degenerative case

/*  
    Array:
      direct access / lgn search if sorted
      but linear for insert and delete
  
    LL:
     easy insert and dete but everything is linear
  
    BST:
      lgn insert / delete / search 
      nlgn building
      BUT: only if full/balanced otherwise
           no better than LL

Common Data Structures used for tree storage:
red/black trees
2/3 trees 
BTree 

Splay tree

*/
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
  std::string a,b,c;
  
  if (n==nullptr){
    return "";
  } else {

    /*
      In order traversal

      1. recursively process the left subtree
      2. Process the current node
      3. recursively process the right subtree

      This will traverse a BSTree in sorted order.

    */
    
      a =  gds_helper(n->getLeft());
      b = std::to_string(n->getData());
      c =  gds_helper(n->getRight());

      /*
       * 
       preorder traversal
       1. process the node
       2. recurse left
       3. recurse right
      */
      
      // a = std::to_string(n->getData());
      // b =  gds_helper(n->getLeft());
      // c =  gds_helper(n->getRight());
    
      /*
       * 
       postorder traversal
       1. recurse left
       2. recurse right
       3. process the node
	*/

      // a =  gds_helper(n->getLeft());
      // b =  gds_helper(n->getRight());
      // c = std::to_string(n->getData());

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
