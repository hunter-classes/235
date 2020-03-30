#include <iostream>

#define ERROR_DIV_BY_ZERO 20


int divide(int a, int b){
  int c;
  if (b==0){
    throw ERROR_DIV_BY_ZERO;
  }
  c = a / b;
  return c;
}

int main(int argc, char *argv[])
{
  int a,b,c;

  a = 10;
  b = 0;
  
  try {
    c = divide(a,b);
    std::cout << c << "\n";
  } catch (int e) {
    std::cout << "We got exception: " << e << "\n";
  }

  
  return 0;
}
