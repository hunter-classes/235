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

void f2(){
  int b;
  std::cout << b << "\n";
}

void f1(){
  int a;
  a = 3;
  std::cout << a << "\n";
}


int main()
	 {
	   for (int i = 1; i < 10; ++i) {
	     std::cout << i << "! = " << fact(i) << "\n";
	   }
	   f1();
	   f2();
	   return 0;
	 }
