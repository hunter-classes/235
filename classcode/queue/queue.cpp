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
    result = result + std::to_string(tmp->getdata()) + "-->";
    tmp = tmp->getNext();
  }
  result = result + "null\n";
  return result;
}

