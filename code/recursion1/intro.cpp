#include <iostream>

int fact_iter(int n){
  int result = 1;
  for (int i = 1; i <= n; i++){
    result = result * i;
  }
  return result;
  
}

int fib_iter(int n){
  int a,b,c;
  if (n < 2){
    return 1;
  } else {
    a = 1;
    b = 1;
    int count = 2;
      while (count <= n){
	c=a+b;
	a=b;
	b=c;
	count = count + 1;
    }
    return c;
  }
  
}

int fact(int n){
  if (n<1){
    // base case
    return 1;
  } else{
    // recursive reduction 
    return n * fact(n-1);
  }
  
}

int fib(int n){
  if (n<3){
    // base case
    return 1;
  } else {
    return fib(n-1) + fib(n-2);
  }
}


int fib_tail(int n, int a, int b, int c){
  if (n==0){
    return a;
  }else{
    return fib_tail(n-1,b,c,b+c);
  }
}

int fib_tail(int n){
  return fib_tail(n,1,1,2);
}

// Dynamic Programming
// memoization 
int fib_table[1000];
int fib_dyn(int n){
  if (n<3){
    return 1;
  } else if (fib_table[n] != 0){
    return fib_table[n];
  } else {
    fib_table[n] = fib_dyn(n-1) + fib_dyn(n-2);
    return fib_table[n];
  }
}

int main()
{

  for (int i = 0; i < 1000; i++){
    fib_table[i] = 0;
  }
  
  
  std::cout << std::endl;
  for(int i = 0; i < 50; i++){
    std::cout << i << " : " << fib_dyn(i) << "\n";
  }
  std::cout << std::endl;

  return 0;
}
