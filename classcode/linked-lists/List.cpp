#include <iostream>

#include "List.h"


List::List(){
  head = nullptr;
  
}

void List::insert(std::string data){
  // create a new node
  Node *new_node = new Node(data);

  // insert the new node
  new_node->setNext(head);
  head=new_node;
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
