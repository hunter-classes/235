#include <iostream>

/*  
    returns the number of ways you can walk up a starcase 
    of "steps" steps if you take them 1, 2, or 3 at a time
 */
int ways(int steps){

  if (steps == 0)
    return 1;

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
  for (n = 1; n < 10; n++) {
    std::cout << n << " : " << ways(n) << "\n";
    
  }
  return 0;
}
