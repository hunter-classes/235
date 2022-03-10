#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>


int freq(std::vector<int> v, int val){
  int count = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == val)
      count++;
  }
  return count;
  
}


int mode1(std::vector<int> v){
  int mod_i = 0;
  int mode_so_far = v[0];
  int mode_count_so_far = freq(v,v[0]);
  for(int i = 1 ; i < v.size();i++){
    int current = freq(v,v[i]);
    if (current > mode_count_so_far){
      mode_so_far = v[i];
      mod_i = i;
    }
  }

  return mode_so_far;
}


void print_vector(std::vector<int> a){
  for (auto i : a) {
    std::cout << i << ", ";
    
  }

  std::cout << "\n";
  
}

int main(int argc, char *argv[])
{
  int m;
  int size = 10000; // default vector size
  int max_val = 100; // default max value for entries

  srand(time(NULL));
  std::vector<int> a(size);
  int i;
  for(i=0;i<size;i++){
    a[i] = rand()%max_val;    
  }
  //  print_vector(a); 

  m = mode1(a);
  std::cout << "mode1: " << m << "\n";
  
  return 0;
}
