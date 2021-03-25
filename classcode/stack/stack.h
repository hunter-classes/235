#pragma once

class stack{
 private:
  int a[5];
  int topindex=0;

  
 public:
  void push(int); // add an item to the top of the stack
  int pop(); // remove and return an item from the top of the stack
  int top();
  bool is_empty(); // return true if the stack is empty;

  /* other common stack things */
  /*
    add_vector(std::vector<int> a) <-- adds all the items in a to the stack 
    int [] get_vector() <-- returns a vector with all the elements in the stack
    swap() <-- swaps the top two elements on the stack
    swap(5) <-- swaps the value at the top of the stack with the value 5 down

    Constructors:
    stack() <- inits an empty stack
    stack(s) <- makes the array of size s
    stack(v) <- make the stack larger than array (vector) v and initializes stack
                with the elements in v


   */
};
