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


int main()
{
  std::cout << fact(5) << "\n";
  int max = 50;
  for(int i = 0; i < max; i++){
    std::cout << fib_iter(i) << ", ";
  }

  std::cout << std::endl;
  for(int i = 0; i < max; i++){
    std::cout << i << " : " << fib(i) << "\n";
  }
  std::cout << std::endl;

  return 0;
}
