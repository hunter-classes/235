#pragma once
#include <iostream>

class Person{
 private:
  std::string first; // first name
  std::string last; // last name
  int idnum; // some id number

 public:
  Person(std::string first, std::string last, int num);
  std::string get_name();
  int get_id();
  
  
};
