#include <iostream>

using std::string;

void hanoi(int n, string s, string d, string t){
  if (n==1){
    std::cout << "Move a disc from " << s << " to " << d << "\n";
  } else {
    hanoi(n-1,s,t,d);
    hanoi(1,s,d,t);
    hanoi(n-1,t,d,s);
  }
}

int main()
{
  hanoi(5,"a","b","c");
  return 0;
}
