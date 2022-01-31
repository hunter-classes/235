#include <iostream>

int fact_iter(int n){
  int product = 1;
  for (int i=1; i <=n ; ++i) {
    product = product * i;
  }
  return product;
}

int fact(int n){
  // a conditional to control everythin
  if (n == 0){
    // the base case (we just know the answer_
    return 1;
  } else {
    // call a simpler version of the routine
    // to eventually get to the base case
    return n * fact(n-1);
  }
}



int fib(int n){
  if (n < 2){
    return 1;
  } else {
    return fib(n - 1) + fib(n -2);
  
  }
}

int fib_iter(int n){
  if (n < 2){
    return 1;
  }

  int a = 1;
  int b = 1;
  int c;
  while (n > 0){
    c = a + b;
    a = b;
    b = c;
    n = n - 1;
    
  }
  return c;
}

int main()
	  {
	    for (int i = 0; i < 100; ++i) {
	      std::cout << i << " :  " << fib(i) << "\n";
	    }
	    return 0;
	  }
