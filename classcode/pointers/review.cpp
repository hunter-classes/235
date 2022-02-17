#include <iostream>

int main()
{
  int a = 11;
  int b = 222;
  int ar[4]= {10,20,30,40};

  int *p1,*p2;
  int i;

  

  
  p1 = &a;
  p2 = &b;

  std::cout << "p1 and a: " << &a << " " << p1 << " " << *p1 << "\n"; 
  std::cout << "p2 and b: " << &b << " " << p2 << " " << *p2 << "\n"; 

  *p1 = 400;

  std::cout << a << "\n";

  p1 = &(ar[0]); // this is the same as saying p1 = ar
  std::cout << *p1 << "\n";
  std::cout << p1[1] << "\n";
  std::cout << p1[3] << "\n";
  std::cout << *(p1+3) << "\n";

  p1++;

  std::cout << *p1 << " "  << p1[0] << "\n";
  
  return 0;
}
