#include <iostream>
#include <stdexcept>
#include "List.h"

List::List() {
  head = nullptr;
}


List::~List(){
  Node *trailer;
  std::cerr << "Destructing\n";
  while(head != nullptr){
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
}

void List::insert(std::string data){
  Node *tmp = new Node(data);
  tmp->setNext(head);
  this->head = tmp;
}

//
// We need a pointer BEFORE
// the insertion point
//
// We use piggybacking
// That is, send a pointer one behind that
// trails the walker.
// When walker points to Node n,
// the trailer points to Node n-1
//
void List::insert(int loc, std::string data){
  Node *tmp = new Node(data);

  Node *walker = head;
  Node *trailer=nullptr; // this one follows behind walker;
  
  while (walker != nullptr && loc > 0){
    trailer = walker;
    walker = walker->getNext();
    loc = loc - 1;
  }
  // walker is at n, trailer is at the point before the insertion
  // point

  // check to see if we're trying to insert beyond the end
  // Note: we can insert a new last element.

  if (loc > 0){
    throw std::out_of_range("Out of range");
  }

  // inserting at location 0 will have trailer = nullptr
  // so we have to deal with that special case
  if (trailer==nullptr){
    tmp->setNext(head);
    head=tmp;
  } else {
    // and finally the normal insert code
    tmp->setNext(walker);
    trailer->setNext(tmp);
  
  }
}

void List::remove(int loc){

  Node *walker = head;
  Node *trailer=nullptr; // this one follows behind walker;

  while (walker != nullptr && loc > 0){
    trailer = walker;
    walker = walker->getNext();
    loc = loc - 1;
  }

  
  // walker is at n, trailer is at the point before the insertion
  // point

  // check to see if we're trying to delete beyond the end
  // Note: we can insert a new last element.

  if (walker == nullptr){
    throw std::out_of_range("Out of range");
  }

  // delete location 0 will have trailer = nullptr
  // so we have to deal with that special case
  if (trailer==nullptr){
    head = walker->getNext();
    delete walker;
  } else {
    // and finally the normal delete code
    trailer->setNext(walker->getNext());
    delete walker;
  }
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
