#pragma once
class stack{
 private:
  int a[5];
  int topindex=0;
  

 public:
  void push(int); // add an item to the top
  int pop(); // remove and return an item from the top of the stack
  int top(); // returns but doesn't remove the value on top
  bool is_empty(); // returns true if stack is empty
    
  /*

    additional common operataions:
    void add+vector(std::vector<int> a) <-- adds all the items in a to stack
    int [] get-vector()  <-- returns an array with all the items
    swap() <-- swaps the top two elements on the stack
    swap(5) <-- swaps the value at top with the value 5 down

    also constructors 
    
  */
};
