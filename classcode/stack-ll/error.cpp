#include <iostream>



#define ERROR_DIV_BY_ZERO 20

int divide(int a, int b){
  int c;

  if (b==0) {
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
  try {
    std::cout << "About to divide\n";
    c = divide(a,b);
    std::cout << c << "\n";
  } catch(int e) {

    std::cout << "We got an exception " << e << "\n";
  }

  std::cout << "and the program continues\n";

  
  return 0;
}
