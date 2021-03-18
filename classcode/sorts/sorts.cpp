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

  // O(n)
  for (i = 0; i < len; ++i) {
    // find the ith smallest element
    // find_min is O(n)
    min_index = find_min_index(a,i,len);
    
    
    // swap it with a[i]
    int tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;
  }

  // overall O(n^2)
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


std::vector<int> qsort(std::vector<int> list){

  if (list.size() <= 1){
    return list;
  }

  // select a pivot  <-- the birthday we chose
  // just select list[0] as your pivot value

  // partition the data set such that all the values <=the pivot
  // are in one vector and all the values > the pivot are in the other

  std::vector<int> lower,higher;

  // at this point we have
  // pivot is list[0]
  // lower has all the values <= pivot
  // higher has all the values > pivot

  // recursively qsort lower
  // recurisively qsort higher

  // copy lower + pivot + higher back into list and return it
  
  
}

void print_help(char *command_name){
  std::cout << "Usage: " << command_name << "[-h | -p | -m N | -s N  | -a algorithm ]" << "\n\n";
  std::cout << "       -m MAX ELEMENT SIZE\n";
  std::cout << "       -a [s | m] : s - selection, m - merge\n";
    
  
}

extern char *optarg;


int main(int argc, char *argv[])
{
  int size = 20; // default vector size
  char algorithm = 's' ; //default to selection sort
  int max_val = 100; // default max value for entries
  bool print = false; // do we print before and after sorting?
  char c;

  while ( ( c = getopt(argc, argv, "phs:m:a:")) != -1){

    switch (c) {
    case 'h' :
      print_help(argv[0]);
      exit(0);
      break;
    case 'p' :
      print = true;
      break;
    case 's' :
      size = std::stoi(optarg);
      break;
    case 'm' :
      max_val = std::stoi(optarg);
      break;
    case 'a':
      algorithm = optarg[0]; // or *optarg
    }
  }
  

  srand(time(NULL));
  std::vector<int> a(size);
  int i;
  for(i=0;i<size;i++){
    a[i] = rand()%max_val;    
  }
  if (print) {
   print_vector(a); 
  }

  std::cout << "Starting the sort!\n";
  struct timeval tp;
  gettimeofday(&tp,NULL);
  long start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;
  if (algorithm == 's'){
    a = ssort(a);
  } else if (algorithm == 'm'){

    a = msort(a);
  }


  gettimeofday(&tp,NULL);
  long current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

  long elapsed = current_time - start_time;
  
  if (print) {
   print_vector(a); 
  }

  std::cout << "Time: " << elapsed << "\n";
  
  return 0;
}
