#include <iostream>
#include "queue.h"
int main()
{
  queue *q = new queue();


  std::cout << q->get_debug_string();

  q->enqueue(5);

  q->enqueue(10);
  q->enqueue(15);
  std::cout << q->get_debug_string();
  int x = q->dequeue();
  std::cout << x << "\n";
  std::cout << q->get_debug_string();
  x = q->dequeue();
  std::cout << x << "\n";
  std::cout << q->get_debug_string();
    x = q->dequeue();
    std::cout << x << "\n";
    std::cout << q->get_debug_string();

  
    try {
      x = q->dequeue();
      std::cout << x << "\n";
    } catch (int e){
      std::cout << " Exception\n";
    
    }
  
    std::cout << q->get_debug_string();

  return 0;
}

