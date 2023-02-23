#pragma once
#include <iostream>
#include "Node.h"

class List{
 private:
  Node *head;
 public:
  List();
  void insert(std::string data);

  std::string toString(); // for testing purposes

  /*
    Try to complete for Monday:
    length()
    get()
    and think about the remove and 
    other insert routine
    
    -------------------
    ~List();
    
    void insert(int loc, std::string data); //0 indexed

  void remove(int loc);

  std::string get(int loc);

  int length(); // the # of elements

  */
  
  

};
