#include "Node.h"

template<class T>
Node<T>::Node() : next(nullptr)
{
}

template<class T>
Node<T>::Node( T item)
{
  this->item = item;
  this->next = nullptr;
}

template<class T>
Node<T>::Node(T item, std::shared_ptr<Node<T>> next)
{
  this->item = item;
  this->next = next;
}

template<class T>
Node<T>::~Node<T>(){
  std::cout << "In the destructor\n";
}
template<class T>
void Node<T>::setItem(T item){
  this->item = item;
}


template<class T>
void Node<T>::setNext(std::shared_ptr<Node<T>> next){
  this->next = next;
}


template<class T>
T Node<T>::getItem() 
{
  return item;
}


template<class T>
std::shared_ptr<Node<T>> Node<T>::getNext()
{
  return next;

}

