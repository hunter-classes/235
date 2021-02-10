#include <iostream>

int fib(int n){

  if (n <2){
    return 1;
  } else {
  return fib(n-1) + fib(n-2);
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
    c = a+b;

    // shift down the sequence
    a = b;
    b = c;
    n = n - 1;
  }
  return a;
  
}

/*
 * in tail recursion, the recursive call is the last thing you do.
 
   you add extra parameters to pass information between the calls.
   essentially you're using recursion as a loop.

*/
int fib_tail(int n, int a, int b, int c){
  if (n==0){
    return a;
  } else {
    return fib_tail(n-1, b, c, b+c);
  }
}




int fib_tail(int n){
  return fib_tail(n,1,1,2);
}

int fibtable[1000];

int fib_dyn(int n){
  if (fibtable[n] != 0){
    return fibtable[n];    
  } else if (n < 2) {
    return 1;
  } else {
    int tmp = fib_dyn(n-1) + fib_dyn(n-2);
    fibtable[n] = tmp;
    return tmp;
  }
}


int main()
{
  int i;
  for (i=0;i<1000;i++){
    fibtable[i]=0;
  }
  
  for (i=0; i < 50; i++){
    std::cout << "fib("<< i << ") : " << fib_dyn(i) << "\n";
    
  }
  
  return 0;
}
