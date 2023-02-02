#include <iostream>


int ways(int steps){

  if (steps==0)
    return 1;

  int w = 0;
  for (int i = 3; i >= 1; i--){
    int r = steps - i;
    if (r >= 0)
      w = w + ways(r);
  }
  return w;
}
int solns[1000000];

int ways_dyn(int steps){

  if (steps==0)
    return 1;

  if (solns[steps] != 0)
    return solns[steps];
  
  int w = 0;
  for (int i = 3; i >= 1; i--){
    int r = steps - i;
    if (r >= 0)
      w = w + ways_dyn(r);
  }
  solns[steps] = w;
  return w;
}



int main()
{
  for (int i = 0; i < 1000000; i++)
    solns[i] = 0;

  
  int ans = ways_dyn(100);
  std::cout << ans << "\n";
  return 0;
}
