#include <iostream>
/*
6! = 6*5!
  5! = 5*4!
  4! = 4*6
  3! = 3*2
  2! = 2*1
  1! = 1 *1
  0! = 1

  fact(n) = {  1 if n = 0
               n * (n-1)! otherwise

*/

int fact(int n){
  if (n == 0){
    return 1;
  } else {
    return n * fact(n-1);
  }
}


int main()
{

  int i;

  for (i=0; i < 10 ; i++){
    std::cout << i << "! = " << fact(i) << "\n";
    
  }
  return 0;
}
