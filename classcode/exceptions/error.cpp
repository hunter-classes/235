#include <iostream>

#define ERROR_DIV_BY_ZERO 20

int divide(int a, int b){
  int c;
  if (b==0){
    throw ERROR_DIV_BY_ZERO; 
  }
  
  c = a/b;
return c;
}

int main()
{
  int a,b,c;
  a = 10;
  b = 0;
  try{
    std::cout << "About to try to divide\n";
    c = divide(a,b);
    std::cout << "result: " <<c<< "\n";

  } catch(int e) {
    std::cout << "We're in the exception handler\n";

  } 
  return 0;
}
