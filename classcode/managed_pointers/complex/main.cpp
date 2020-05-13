#include <iostream>
#include <string>
#include <memory>
#include "Node.h"


using std::string;

void f(){
  auto in = std::make_shared<Node<int>>(123);
  auto sn = std::make_shared<Node<std::string>>("Hello ");
  auto sn2 = std::make_shared<Node<std::string>>("World ");

  std::cout << sn.use_count() << "\n";
  std::cout << sn2.use_count() << "\n";
  sn->setNext(sn2);
  sn2->setNext(sn);
  std::cout << sn.use_count() << "\n";
  std::cout << sn2.use_count() << "\n";


  std::cout << sn->getItem() << "\n";
  std::cout << sn2->getItem() << "\n";
  std::cout << in->getItem() << "\n";


}

int main()
{
  f();
  return 0;
}
