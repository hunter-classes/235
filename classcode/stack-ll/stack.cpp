#include <iostream>
#include "stack.h"


stack::stack(){
  head = nullptr;
  }

stack::~stack(){
  if (head != nullptr) {
    Node *t, *t2;

    t = head;
    while (t!=nullptr){
      t2 = t;
      t = t->getNext();
      delete t2;
    }
  }
}


void stack::push(int item){
  Node *tmp = new Node(item);
  tmp->setNext(head);
  head = tmp;
}

int stack::pop(){
  int val;
  if (head==nullptr){
    throw STACK_ERR_EMPTY;
  }
  Node *tmp = head;
  val = head->getData();
  head = head->getNext();
  delete tmp;
  return val;
}

int stack::top(){
  if (head==nullptr){
    throw STACK_ERR_EMPTY;
  }
  return head->getData();
}
bool stack::is_empty(){
  return head == nullptr;
}
