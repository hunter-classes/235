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


int main()
{
  int n;
  for (n=1 ; n < 40 ; n++) {
    std::cout << n << " : " << ways(n) << "\n";
  }
  return 0;
}
