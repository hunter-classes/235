#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "Node.h"

int main()
{
  Node *n,*n2;
  srand(time(0));
  n = new Node();
  n2 = new Node("Hello");
  n->setData("World");
  
  std::cout << n->getData() << " " << n2->getData() << "\n";

  n->setNext(n2);

  std::cout << n->getData() << " " << n->getNext()->getData() << "\n";

  n->getNext()->setNext(new Node("!"));
  std::cout << n->getData() << " " << n->getNext()->getData() << n->getNext()->getNext()->getData() << "\n";

  std::cout << n2->getData() << " " << n2->getNext()->getData()  << "\n";

  //n2->getNext()->setNext(n);
  n2 = n2->getNext();
  n2->setNext(n);
  std::cout << n2->getNext()->getNext()->getData() << "\n";

  while(true){

    std::cout << n->getData() << "\n";
    if (rand()%10==1){
    std::cout << "\n\n*****************adding stuff**********\n\n";
    Node *t = new Node("newstuff");
    t->setNext(n->getNext());
    n->setNext(t);
    n=n->getNext();
    }
    n = n->getNext();
    usleep(500000);
    
    
  }
  return 0;
}
