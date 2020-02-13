#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"

List::List(){
  head = nullptr;
  len=0;
}

List::~List(){

  std::cout << "In the destructor\n";
  Node *t;
  while (head != nullptr){
    t = head;
    head=head->getNext();
    delete t;
    }
}
void List::insert(std::string data){
  // make the new node
  Node *t = new Node(data);
  
  // insert it into the list
  t->setNext(head);
  head = t;
  // update the length
  len++;
}

std::string List::getDebugString(){
  Node *t;
  t = head;
  std::string result="";
  while (t != nullptr){
    result = result + t->getData() + "-->";
    t = t->getNext();
  }
  result = result + "null";

  return result;
}

int List::length(){
  // Node *t = head;
  // int l = 0;
  // while (t!=nullptr){
  //   t=t->getNext();
  //   l++;
  // }
  // return l;
  return len;
}
