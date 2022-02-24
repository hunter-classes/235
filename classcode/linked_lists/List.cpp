#include <iostream>

#include "List.h"

List::List() {
  head = nullptr;
}

void List::insert(std::string data){
  Node *tmp = new Node(data);
  tmp->setNext(head);
  this->head = tmp;
  
}

std::string List::get(int loc){
  std::string result = "";
  Node *walker = head;

  // using walker as a boolean is
  // the same as writing walker != nullptr
  while (walker && loc > 0){
    walker = walker->getNext();
    loc--;
  }
  if (walker)
    return walker->getData();
  else
    return "";
    

}

int List::length(){
  int l = 0;
  Node *walker = head;
  while (walker){
    l++;
    walker = walker->getNext();
  }
  return l;
}


std::string List::toString(){
  std::string result = "";
  Node *walker = this->head;
  while (walker != nullptr){
    result = result + walker->getData() + "->";
    walker = walker->getNext();
  }
  result = result + "null";
  return result;
}
