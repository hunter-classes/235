#include "stack.h"

// issues:
// we're not doing ANY error checking (bounds, data types etc)


void stack::push(int item){
  if (topindex >=5){
    throw STACK_ERR_FULL;
  }
  
  a[topindex] = item;
  topindex++;
}

int stack::pop(){
  if (topindex <= 0){
    throw STACK_ERR_EMPTY;
  }
  int tmp = a[topindex-1];
  topindex--;
  return tmp;
}

int stack::top(){
  if (topindex < 0){
    throw STACK_ERR_EMPTY;
  }
  return a[topindex-1];
}

bool stack::is_empty(){
  return topindex == 0;
}


  
