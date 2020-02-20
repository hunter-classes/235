#include <iostream>

#include <string>
#include "Node.h"

class List{
private:
    std::string dummy="";
  Node *head;
public:
  List();
  ~List();
  void insert(std::string data);
  std::string getDebugString();
  void push_back(std::string);
  int size() ;
  void remove(int i);
  std::string &operator[](int); // overloaded square brackets
};


