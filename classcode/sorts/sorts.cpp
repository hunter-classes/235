#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>


void print_vector(std::vector<int> a){
  for (auto i : a) {
    std::cout << i << ", ";
    
  }

  std::cout << "\n";
  
}


int find_min_index(std::vector<int> a, int start_index, int stop_index){
  int min_index = start_index;
  int i;
  for (i = start_index ; i < stop_index; i++) {
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){
  int i,j;
  int len = a.size();
  int min_index;

  for (i = 0; i < len; ++i) {
    // find the ith smallest element
    min_index = find_min_index(a,i,len);
    
    
    // swap it with a[i]
    int tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;
  }
  return a;
}


std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
  int i = 0; 
  int j = 0;
  std::vector<int> merged;
  while(i < left.size() && j < right.size())
  {
    if(left[i] <= right[j])
    {
      merged.push_back(left[i]);
      i++;
    }
    else 
    {
      merged.push_back(right[j]);
      j++;
    }
  }
  
  while(j != right.size())
    {
      merged.push_back(right[j]);
      j++;
    }
  while(i != left.size())
    {
      merged.push_back(left[i]);
      i++;
    }
  

  return merged;
}


std::vector<int> msort(std::vector<int> list){

  // base case
  if (list.size() <= 1 ){
    return list;
  }

  // split
  int mid = list.size() / 2;
  std::vector<int> a,b;
  int i;
  for (i=0;i<mid;i++){
    a.push_back(list[i]);
  }

  for (i=mid;i<list.size();i++){
    b.push_back(list[i]);
  }
  
  // recurse
  a = msort(a);
  b = msort(b);
  // merge
  list = merge(a,b);
  return list;
  
}

int main()
{
  srand(time(NULL));
  std::vector<int> a(20);
  int i;
  for(i=0;i<20;i++){
    a[i] = rand()%100;    
  }
  print_vector(a);
  a = msort(a);
  print_vector(a);

  
  return 0;
}
