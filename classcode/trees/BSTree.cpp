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


void delete(Node *n,int value){
  if (root==nullptr){
    return;
  }

  // search for the insertion point
  Node *t = root;
  Node *t2;
  while (t!=nullptr && t.getData()  != value){
    t2 = t;
    
    if (t->getData() < value)
      t = t->getRight();
    else
      t = t->getLeft();
  }

  // if t == nullptr then the value isn't
  // in the tree
  if (t==nullptr)
    return;

  // t points to the node we want to delete
  // t2 points to its parent
  
  // The node we want to delete is a leaf
  // point t2's appropriate pointer to null
  
  // The node we want to delete has one child
  // point t2's appropriate pointer to t's
  // child

  // Note - the above two cases can be combined
  
  // the node we want to delete has two children
  // 1. Replace the node we want to delete
  //    with either the largest value in its
  //    left subtree or the smallest value in
  //    its right subtree 
  
  // we find the largest on the left subtree by
  // going to left child and then as far right as
  // we can

  // we find the smallest on the right subtree by
  // going to the right child and then as far left
  // as we can.

  // 2. We can then delete the node that we relaced
  //   from by recursively calling delete
  // on the subtree where that node lives.


}

void delete(int value){
  delete (root,value);
}
