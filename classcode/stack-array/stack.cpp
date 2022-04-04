#include "stack.h"

// issues:
// we're not doing ANY error checking (bounds, data types etc)


void stack::push(int item){
  a[topindex] = item;
  topindex++;
}

int stack::pop(){
  int tmp = a[topindex-1];
  topindex--;
  return tmp;
}

int stack::top(){
  return a[topindex-1];
}

bool stack::is_empty(){
  return topindex == 0;
}


  
