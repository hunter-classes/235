#include <iostream>
#include <string>
#include <memory>
#include "Node.h"


using std::string;

void f(){
  auto in = std::make_shared<Node<int>>(123);
  auto sn = std::make_shared<Node<std::string>>("Hello ");
  auto sn2 = std::make_shared<Node<std::string>>("World ");

  std::cout << "sn use count: " << sn.use_count() << "\n";
  std::cout << "sn2 use count: " << sn2.use_count() << "\n";
  std::cout << "We're now setting next for both\n";
  // these next two lines result in a memory leak
  // because we never have the use count going to zero.
  // without them (or even without both of them
  // then the managed pointer system will automatically
  // free both 
  sn->setNext(sn2);
  sn2->setNext(sn);
  std::cout << "sn use count: " << sn.use_count() << "\n";
  std::cout << "sn2 use count: " << sn2.use_count() << "\n";


  std::cout << sn->getItem() << "\n";
  std::cout << sn2->getItem() << "\n";
  std::cout << in->getItem() << "\n";


}

int main()
{
  f();
  return 0;
}
