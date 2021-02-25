#include <iostream>

#include "List.h"


List::List(){
    head = nullptr;
  
}

List::~List(){
  Node *trailer;
  std::cerr << "destructing\n";
  while (head != nullptr){
    trailer = head;
    head = head->getNext();
    delete trailer;
  }

  
}
void List::insert(std::string data){
  // create a new node
  Node *new_node = new Node(data);

  // insert the new node
  new_node->setNext(head);
  head=new_node;
  }

void List::insert(int loc, std::string data){
  Node *t;
  Node *trailer = nullptr; 
  t = head;

  // in order to insert before location n we need a pointer
  // at the location one before location n
  
  while (t!=nullptr && loc > 0){
    trailer = t;
    t = t->getNext();
    loc = loc - 1;
  }

  // if loc > 0 at this point then the list wasn't long
  // enough to do at an insertion at loc. 
  if (loc > 0){
    return;
  }

  // now, since loc = 0, t points to "n" the location before which
  // we want to insert and trailer points to the node before it.
  // but inserting at the very head is a specail case.

  Node *new_node = new Node(data);

  // check for insertion at the beginning
  if (trailer==nullptr){
    new_node->setNext(t);
    // this is a special case - we're changing the front of the list so
    // we have to change head, not t.
    head = new_node; 
} else {
  
  new_node->setNext(t); // this could also be new_node->setNext(trailer->getNext());
  trailer->setNext(new_node);
  }
}

void List::remove(int loc){
  Node *t;
  Node *trailer = nullptr; 
  t = head;

  while (t!=nullptr && loc > 0){
    trailer = t;
    t = t->getNext();
    loc = loc - 1;
  }

  // if loc > 0 at this point then the list wasn't long
  // enough to do at an insertion at loc. 
  if (loc > 0){
    return;
  }
  // check for removing the first node
  if (trailer==nullptr){
    head = head->getNext(); 
} else {
  
    trailer->setNext(t->getNext());
    
  }
  
}

std::string List::get(int loc){
  // start at the front
  Node *t;
  t = head;
  // walk down until we're at the location
  while (t  != nullptr && loc > 0){
    t = t->getNext();
    loc = loc - 1;
  }
  if (t != nullptr) {
    return t->getData();
  } else {
    return "";
  }
}

std::string List::toString(){
  Node *walker = head;
  std::string s = "";
  while (walker != nullptr){
    s = s + walker->getData() + "-->";
    walker = walker->getNext();
    
  }
  s=s+"nullptr";
  return s;
  
}
