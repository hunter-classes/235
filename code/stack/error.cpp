#include <iostream>

#define ERROR_DIV_BY_ZERO 120

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

  try {
    std::cout << "About to divide\n";
    c = divide(a,b);
    std::cout << "result: " << c << "\n";
  } catch (int e){
    std::cout << "Handling the exception here, e was:" << e << "\n";
  }

  std::cout << "After the try catch \n";
  
  return 0;
}
