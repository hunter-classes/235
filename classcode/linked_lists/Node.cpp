#include <iostream>
#include "Node.h"

Node::Node() : next(nullptr)
{
}

Node::Node(std::string data){
  this->data = data;
  this->next = nullptr;
}
Node::Node(std::string data, Node *next){
  this->data = data;
  this->next = next;
}

void Node::setData(std::string data){
  this->data = data;
}

void Node::setNext(Node *next){
  this->next = next;
}

std::string Node::getData(){
  return this->data;
}

Node *Node::getNext(){
  return this->next;
}
