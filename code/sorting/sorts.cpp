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

/*
  left and right are already sorted low to high

  create a new std::vector named merged
  and fill it with all the elements of left and right.
  When done, merged should be in order low to high.

*/
std::vector<int> merge(std::vector<int> left,
		       std::vector<int> right){
  std::vector<int> merged;
  int l,r; // indices into left and right;

  while (l < left.size() && r< right.size()){
    if (left[l] < right[r]){
      merged.push_back(left[l]);
      l++;
    } else {
      merged.push_back(right[r]);
      r++;
    }
  }

  while (l < left.size()){
    merged.push_back(left[l]);
    l++;
  }
  while (r < right.size()){
    merged.push_back(right[r]);
    r++;
  }
     
  return merged;
}

std::vector<int> msort(std::vector<int> data){
  std::vector<int> result;)
  // if the size of data is <= 1 just return data

  // othewise
  // split data into 2 std::vectors left and right
  // of equal size (or off by 1)
  // then:
  //   left = msort(left);
  //   right = msort(right);
  //   result= merge(left,right);
  // 
  return result;
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


  // print_vector(a);
  // std::vector<int> b = ssort(a);
  // print_vector(b);

  std::vector<int> left,right;
  for (int i = 0; i < 10; i++){
    left.push_back(rand()%max_val);
    right.push_back(rand()%max_val);
  }
  left = ssort(left);
  right = ssort(right);
  print_vector(left);
  print_vector(right);
  std::cout << "\n----------\n";
  std::vector<int> merged = merge(left,right);
  print_vector(merged);
  return 0;
}
