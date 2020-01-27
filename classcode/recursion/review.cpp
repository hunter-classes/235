#include <iostream>



int fact1(int x){
  if (x <= 1)
    return 1;
  else
    return x * fact1(x-1);
}


int fact(int x,int ans){
  if (x <= 1)
    return ans;
  else
    return fact(x-1,ans * x);
}


int fib(int n){
  if (n < 2)
    return 1;
  else
    return fib(n-1)+fib(n-2);
  
}

int fib_iter(int n){
  int a = 1;
  int b = 1;
  int c = a + b;
  while (n > 0){
    a = b;
    b = c;
    c = a + b;
    n--;
  }
  return a;
}

int fibarray[1000];

int fib_dyn(int n){
  if (n < 2)
    return 1;
  else{
    if (fibarray[n]!=0)
      return fibarray[n];
    else {
      int c = fib_dyn(n-1)+fib_dyn(n-2);
      fibarray[n]=c;
      return c;
	
    }
    
  }
  return fib(n-1)+fib(n-2);
  
}

int fib_tail(int n, int a, int b, int c){
  if (n == 0)
    return a;
  else
    return fib_tail(n-1,b,c,b+c);
}

int main()
 {
   int i;
   
   for (i = 0; i < 1000; ++i) {
     fibarray[i]=0;
   }
   
   for (i = 0; i < 200; ++i) {
     std::cout << fib_tail(i,1,1,2) << "\n";
   }

   std::cout << fact(5,1)<<"\n";
   return 0;
 }
