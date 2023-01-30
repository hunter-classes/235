#include <iostream>

void move(char src, char dst, char tmp){
  std::cout << "Move from " << src << " to " << dst << " using " << tmp << "\n";
}



void hanoi(int n, char src, char dst, char tmp){
  if (n==1){
    move(src,dst,tmp);
  } else {
    hanoi(n-1,src,tmp,dst);
    hanoi(1,src,dst,tmp);
    hanoi(n-1,tmp,dst,src);

  }
  
  
}

int main()
{
  hanoi(1,'a','b','c');
  std::cout << "\n\n";
  hanoi(2,'a','b','c');
  std::cout << "\n\n";
  hanoi(3,'a','b','c');
  std::cout << "\n\n";
  hanoi(4,'a','b','c');
  std::cout << "\n\n";
  hanoi(5,'a','b','c');
  std::cout << "\n\n";
  
  return 0;
}
