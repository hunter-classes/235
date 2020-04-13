#include <iostream>

#include <string>
#include "List.h"

List::List(){
  head = nullptr;
}

List::~List(){
  std::cout << "In the destructor\n";
  if (head != nullptr){
    Node *t,*t2;
    
    t=head->getNext();
    while (t!=nullptr){
      t2=t;
      t=t->getNext();
      delete t2;
    }
    delete head;
  }
  
  
}

void List::insert(std::string data){
  Node *t = new Node(data,nullptr);
  if (head==nullptr)
    head=t;
  else{
    t->setNext(head);
    head = t;
  }
}

std::string List::getDebugRHelper(Node *l){
  if (l==nullptr){
    return "";
  } else {
    return l->getData() + "-->" + getDebugRHelper(l->getNext());
  } 
  
}
std::string List::getDebugR(){
  return getDebugRHelper(head);
}
std::string List::getDebugString(){
  std::string s = "";
  Node *t = head;
  while (t != nullptr){
    s = s + t->getData()+"->";
    t=t->getNext();
  }
  s=s+" NULL\n";
  return s;
}

void List::push_back(std::string s){
  Node *t = new Node(s);
  if (head==nullptr)
    head = t;
  else{
    Node *t2=head;
    while (t2->getNext()!=nullptr)
      t2=t2->getNext();
    t2->setNext(t);
  }
}

int List::size(){
  Node *t = head;
  int i = 0;
  while (t!=nullptr){
    t=t->getNext();
    i++;
  }
  return i;
}

void List::remove(int i){
  Node *t, *t2;
  if (i>size()-1)
    return;
  if (i==0){
    t=head;
    head=head->getNext();
    delete t;
    return;
  }
  t=head;
  while (i>0){
    i--;
    t2=t;
    t=t->getNext();
  }
t2->setNext(t->getNext());
 delete t;
}

std::string &List::operator[](int i){
  
  if (i>size()-1)
    return dummy;
  Node *t = head;
  while (i>0){
    i--;
    t=t->getNext();
  }
  return t->getRef();
}
