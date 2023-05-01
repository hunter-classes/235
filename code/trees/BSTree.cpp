#include <iostream>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree(){
  root = nullptr;
}




// Traversal - visit every node in the tree
// O(n)
std::string BSTree::traverse(Node *n){
  std::string a,b,c;
  
  if (n==nullptr){
    return "";
  } else {


    /*
     *  pre-order traversal
     1. process the node
     2. recurse to left subtree
     3. recurse to right subtree

     a = std::to_string(n->getData());
     b =  traverse(n->getLeft());
     c =  traverse(n->getRight());


     * post-order traversal

     1. recurse to left subtree
     2. recurse to right subtree
     3. process the node
      
     a =  traverse(n->getLeft());
     b =  traverse(n->getRight());
     c = std::to_string(n->getData());

    */

    /*  
	in-order traversal

	1. recurse left subtree
	2. process node
	3. recurse right subtree
    */

    a = traverse(n->getLeft());
    b = std::to_string(n->getData());
    c = traverse(n->getRight());
    

return a + ", " + b+ ", " + c;

     
  }
}

std::string BSTree::get_debug_string(){
  return traverse(root);
}

/*
  if the BST is full/balanced
  this will behave like a binary search - remove 1/2
  the data set each time through
  so O(lgn) preformance

  IF THE tree isn't full/balanced it degenerates
  into a linked list and you only get O(n)

*/
int BSTree::search(int n){
  Node *current = root;

  
  while (current != nullptr){
    int node_val = current->getData();
    if (n == node_val){
      return node_val;
    } else if (n < node_val){
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  throw 1; // returning a not found value would be better
  
}

/*
  if the BST is full/balanced
  this will behave like a binary search - remove 1/2
  the data set each time through
  so O(lgn) preformance

  IF THE tree isn't full/balanced it degenerates
  into a linked list and you only get O(n)
*/
void BSTree::insert(int n){
  Node *new_node = new Node(n);

  // special case if the tree is empty
  if (root == nullptr){
    root = new_node;
    return;
  }

  // search for the insertion point
  Node *current = root;
  Node *trailer = nullptr;
  while (current != nullptr){
    trailer = current; // catch the trailer up
    int val = current->getData();
    if (n == val){
      // update the node with the additional stuff
      return;
    } else if (n < val){
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  // if we get here, trailer points to the
  // node above the new node's location
  if (n < trailer->getData()){
    trailer->setLeft(new_node);
  } else {
    trailer->setRight(new_node);
  }
     
}

int BSTree::treesum(Node *n){
  if (n==nullptr){
    return 0;
  } else {
    int value = n->getData();
    return value + treesum(n->getLeft())
      + treesum(n->getRight());
  }
}

int BSTree::treesum(){
  return treesum(root);
}

int BSTree::countodds(Node *n){
  if (n==nullptr){
    return 0;
  } else {
    int data = n->getData();
    int value;
    if (data%2==0) {
      value = 0;
    } else {
      value = 1;
    } 
    return value + countodds(n->getLeft())
      + countodds(n->getRight());
  }
}

int BSTree::countodds(){
  return countodds(root);
}
int BSTree::oddsum(Node *n){
  if (n==nullptr){
    return 0;
  } else {
    int data = n->getData();
    int value;
    if (data%2==0) {
      value = 0;
    } else {
      value = data;
    } 
    return value + oddsum(n->getLeft())
      + oddsum(n->getRight());
  }
}

int BSTree::oddsum(){
  return oddsum(root);
}


void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(8);
  n2->setRight(n);
  
}


