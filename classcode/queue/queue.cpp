#include <iostream>
#include "queue.h"

//     node1-->node2-->node3-->null
// head--^                ^-----------tail



queue::queue(){
  head = nullptr;
  tail = nullptr;
}

std::string queue::get_debug_string(){
  std::string result = "";
  Node *tmp = head;

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
  } else {
    tail->setNext(tmp);
    tail = tmp;
  }

}

int queue::dequeue(){
  if (head == nullptr){
    throw QUEUE_ERR_EMPTY;
  }
  int retval = head->getData();
  Node *tmp = head;
  head = head->getNext();
  delete(tmp);

  // if we just emptied the queue, fix where tail points to
  if (head == nullptr){
    tail = nullptr;
  }
  return retval;
}

int queue::front(){
  if (head == nullptr){
    throw QUEUE_ERR_EMPTY;
  }

  return head->getData();
  
}
