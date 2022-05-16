#pragma once
#include <iostream>
#include <string>
#include <memory>
using std::string;

template <class T>
class Node{
private:
  T item;
  std::shared_ptr<Node<T>> next; // instead of a Node *
public:
  Node<T>();
  Node<T>(T item);
  Node<T>(T item, std::shared_ptr<Node<T>> next);
  ~Node<T>();
  void setItem(T item);
  void setNext(std::shared_ptr<Node<T>> next);
  T getItem() ;
  std::shared_ptr<Node<T>> getNext();
};

#include "Node.hxx"
