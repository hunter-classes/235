#include <iostream>
#include "queue.h"

queue::queue(){
  head = nullptr;
  tail = nullptr;
  
}


//               node2-->node3-->null
//         head---^       ^--------tail


std::string queue::get_debug_string(){
  Node *tmp = head;
  std::string result = "";

  while (tmp != nullptr){
    result = result + std::to_string(tmp->getData()) + "-->";
    tmp = tmp->getNext();
  }
  result = result + "null\n";
  return result;
}

void queue::enqueue(int data){
  Node *tmp = new Node(data);
  if (head==nullptr){
    head = tmp;
    tail = tmp;
  } else{
    tail->setNext(tmp);
    tail = tmp;
  }
}

int queue::dequeue(){
  if (head==nullptr){
    throw QUEUE_ERR_EMPTY;
  }

  int data = head->getData();
  Node *tmp = head;
  head = head->getNext();
  delete tmp;

  if (head == nullptr){
    tail = nullptr;
    
  }
  return data;
}

/*
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
*/
