#include <iostream>

struct s {
  int a,b;
};


int main()
{

  int a = 11;
  int b = 222;

  int ar[4] = {10,20,30,40};

  int *p1,*p2;
  int i;
  

  p1 = &a;
  p2 = &b;
  std::cout << &p1 << " " << p1 << " " <<  *p1 << "\n";
  std::cout << &p2 << " " << p2 << " " <<  *p2 << "\n";

  p1 = &ar[0];
  std::cout << *p1 << "\n";
  p1++;
  std::cout << *p1 << "\n";
  std::cout << *(p1+1) << "\n";
  // a[i] is equivalent to *(a+i)

  // so, ar[0] is *(ar+0) is *ar
  // ar[1] is *(ar + 1) etc

  p1 = &ar[2];

  p1 = new int;
  *p1 = 23;
  std::cout << &p1 << " " << p1 << " " <<  *p1 << "\n";
  delete p1;
std::cout << &p1 << " " << p1 << " " <<  *p1 << "\n";
  
  

  
  std::cout << *p1 << "\n";


  struct s st;
  st.a = 10;
  st.b = 20;

  struct s *sp;

  sp = &st;

  std::cout << (*sp).a << "\n";;
  std::cout << sp->b << "\n";;
  // sp->b is the same as (*sp).b

  sp = new struct s;
  sp->a = 111;
  sp->b = 222;
  std::cout << (*sp).a << "\n";;
  std::cout << sp->b << "\n";;
  delete sp;



  return 0;
}
