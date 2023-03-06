#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <cstdlib>
#include <math.h>

// compile with -fconcepts and you
// can make the std::vector<int>
// into std::vector<auto>
void print_vector(std::vector<int> a){
  for(auto item:a){
    std::cout << item << ", ";
  }
  std::cout << "\n";
}


int find_min_index(std::vector<int> a,
		   int start_index,
		   int stop_index){
  int min_index = start_index;
  int i;
  for (i = start_index; i < stop_index; i++){
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){
  int i,min_index,tmp;
  int len = a.size();

  for (i=0;i<len;i++){
    min_index = find_min_index(a,i,len);

    tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;
  }
  return a;
}


int main()
{
  int size = 20;
  int max_val = 100;
  srand(time(nullptr));
  std::vector<int> a(size);
  for (int i = 0; i < size; i++){
    a[i] = rand()%max_val;
  }


  print_vector(a);
  std::vector<int> b = ssort(a);
  print_vector(b);

  return 0;
}
