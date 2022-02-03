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

int fib_tail(int n, int a, int b, int c){
  if (n == 0)
    return a;
  else {
    return fib_tail(n-1,b,c,b+c);
  }
}

int fib_t(int n){
  return fib_tail(n,1,1,2);
}

int fibtable[10000];
int fib_dyn(int n){

  if (n < 2){
    return 1;
  } else if (fibtable[n] != 0){
    return fibtable[n];
  } else {
    int tmp = fib_dyn(n-1) + fib_dyn(n-2);
    fibtable[n]=tmp;
    return tmp;
  }
}


int main()
{
  int i;

  for (i=0;i<10000;i++){
    fibtable[i]=0;
  }
    
  for (i = 0; i < 100; ++i) {
    std::cout << i << " :  " << fib_dyn(i) << "\n";
  }
  return 0;
}
