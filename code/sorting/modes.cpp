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

// the same idiom
// as finding the largest (or smallest)
// in a vector/array/list
int mode(std::vector<int> v){
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

int fast_mode(std::vector<int> v){
  // find the largest value
  // takes one time through the data
  int max_val = 0;
  for (auto i: v){
    if (i > max_val){
      max_val = i;
    }
  }

  // make a vector of size max_val to be
  // buckets for the tallies
  std::vector<int> counts(max_val +1);

  // make the tallies
  // takes one time through the data
  for (auto i : v){
    counts[i]++;
  }

  // find the largest tally
  // takes one time through the counts vector
  int mode_index = 0;
  for (int i = 0; i < max_val +1; i++){
    if (counts[i] > counts[mode_index]){
      mode_index = i;
    }
  }
  return mode_index;
  
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
  int size = 10000000; // default vector size
  int max_val = 100; // default max value for entries

  srand(time(NULL));
  std::vector<int> a(size);
  int i;
  for(i=0;i<size;i++){
    a[i] = rand()%max_val;    
  }
  //print_vector(a); 

  //m = mode(a);
  //std::cout << "mode: " << m << "\n";
  int m2 = fast_mode(a);
  std::cout << "mode: " << m2 << "\n";
  
  return 0;
}
