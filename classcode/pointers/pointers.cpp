#include <iostream>
struct s {
  int a,b;
};




int main()
{
  int a=1;
  
  int c=100;

  int *p;

  int ar[3];

  struct s st;
  st.a = 10;
  st.b=20;
  struct s *sp;

  sp = &st;

  std::cout << (*sp).b << "\n";
  
  sp->b = 12345;
  std::cout << (*sp).b << "\n";
  std::cout << sp->b << "\n";
  std::cout << st.b << "\n";

  p = new int;
  *p=300;
  std::cout << *p << "\n";
  delete p;

  sp = new struct s;
  sp->a = 20;
  sp->b = 30;
  std::cout << (*sp).b << "\n";
  std::cout << sp->b << "\n";
  delete sp;

  int *ax = new int[10];
  delete[] ax;

  return 0;
}
