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
  // new returns nullptr if it couldn't allocate memory
  if (tmp==nullptr){
    throw STACK_ERR_FULL;
  }
  tmp->setNext(head);
  head = tmp;
}


/* 
   if the stack is empty  it's an error condition to pop it.
   we can't just return 0 becuase 0 could be a valid value in a 
   non empty stack so we need a better way to handle this.
*/
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
