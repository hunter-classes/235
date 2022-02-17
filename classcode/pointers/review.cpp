#include <iostream>

struct s {
  int a,b;
};

int main()
{
  int a = 11;
  int ar[4]= {10,20,30,40};
  int b = 222;

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

  std::cout << p1[-1] << "\n";

  std::cout << "a: " << a << " b: " << b << "\n";

  // for (int i = -20 ; i <=0; i++)
  //   ar[i] = 111111;
  
  // std::cout << "a: " << a << " b: " << b << "\n";

  // std::cout << &a << " " << &b << " " << &(ar[0]) << "\n";


  p1 = new int;
  *p1 = 23;
  std::cout << &p1 << " " << p1 << " " << *p1 << "\n";

  delete p1;
  std::cout << &p1 << " " << p1 << " " << *p1 << "\n";

  p2 = new int;
  *p2 = 12345;

  // note that it might reuse the same memory if available
  std::cout << &p1 << " " << p1 << " " << *p1 << "\n";

  struct s st;
  st.a = 10;
  st.b = 20;

  struct s *sp;

  sp = &st;

  std::cout << (*sp).b << "\n";

  (*sp).b = 30;

  std::cout << st.b << "\n";

  sp->a = 100;
  std::cout << sp->a << " " << st.a << "\n";

  // using pointers to make an array
  int *ap = new int[10];
  // but we delete it with this
  delete[] ap;

  sp = new struct s;

  sp->a = 100;
  sp->b = 200;
  std::cout << sp << ":" << sp->a << " " << sp->b << "\n";
  delete sp;;
  std::cout << sp << ":" << sp->a << " " << sp->b << "\n";
  return 0;
  
}
