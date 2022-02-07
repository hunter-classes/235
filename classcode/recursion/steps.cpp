#include <iostream>

int ways(int steps){

  // base case - we have no steps left
  if (steps == 0)
    return 1;
  
  // recursive reduction
  // how many ways can we do n-1 steps, n-2 steps and n-3 steps
  // and add them up
  int w = 0;
  for (int i = 3; i >= 1; i--){
    int r = steps - i;
    if (r >= 0)
      w = w + ways(r);
  }
  return w;
  
}


int solns[100000];

int ways_mem(int steps){

  // base case - we have no steps left
  if (steps == 0)
    return 1;

  if (solns[steps] != 0){
    return solns[steps];
  }
  
  // recursive reduction
  // how many ways can we do n-1 steps, n-2 steps and n-3 steps
  // and add them up
  int w = 0;
  for (int i = 3; i >= 1; i--){
    int r = steps - i;
    if (r >= 0)
      w = w + ways_mem(r);
  }
  solns[steps] = w;
  return w;
  
}


int main()
{
  int n;
  for (n=0;n<100000;n++){
    solns[n]=0;
  }
  
  for (n=1 ; n < 50 ; n++) {
    std::cout << n << " : " << ways_mem(n) << "\n";
  }
  return 0;
}
