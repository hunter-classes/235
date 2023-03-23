#include <iostream>

/*
  constant time - set # of lines / instructions
  linear time - a single loop
  quadratic - a loop within a loop
  cubic - 3 nested loops
  (nested loops is polynomial time) 
 */
int sq(int x){
  return x*x;
}


int main()
{
  int x;
  int i,j,k;
  int n=1000;


  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      x = sq(5);
    }
  }

  for (i=0;i<n;i++){
    // something
  }
  for (i=0;i<n;i++){
    // something
  }
  
  // SOMETHING 
  return 0;
}
