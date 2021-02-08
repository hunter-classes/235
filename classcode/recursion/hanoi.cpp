#include <iostream>
/*
 * 
 can only move one disc at a time
discs must be either in transit or on a tower (never on the ground)
you can never place a larger disc on a smaller disc

*/


void move(char src, char dst){
  std::cout << "Move a disc from " << src << " to " << dst << "\n";
}
void hanoi(int n, char src, char dst, char tmp){
  if (n==1){
    move(src,dst);
      } else {
    hanoi(n-1, src, tmp,dst);
    hanoi(1,src,dst,tmp);
    hanoi(n-1,tmp,dst,src);
  }
}

int main(int argc, char *argv[])
{
  hanoi(4,'a','b','c');
  return 0;
}
