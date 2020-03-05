#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

int find_min(std::vector<int> a, int start_index, int stop_index){
  int min_index = start_index;
  int i;
  for (i = start_index; i < stop_index; i++){
    if (a[i] < a[min_index])
      min_index = i;
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){

  int i,j;
  int l = a.size();
  int min_index;

  for (i = 0; i < l; ++i) {
    min_index = find_min(a,i,l);
    int tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;
  } 
  return a;
}

  
void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}

std::vector<int> merge(std::vector<int> a, std::vector<int> b){
  int ai=0;
  int bi=0;
  std::vector<int> result;
  while(ai<a.size() && bi<b.size()){
    if (a[ai] < b[bi]){
      result.push_back(a[ai]);
      ai++;
    } else {
      result.push_back(b[bi]);
      bi++;
    }
  }
  // we know we finished one list, a or b but the
  // other will still have at least one element on it.

  while (ai < a.size()){
    result.push_back(a[ai]);
    ai++;
  }

  while (bi < b.size()){
    result.push_back(b[bi]);
    bi++;
  }
  return result;
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
  int i;
  if (list.size() <= 1)
    return list;

  std::vector<int> lower,upper;
  int pivot = list[0];

  // partition data set into lower and upper
  for (i = 1; i < list.size(); i++) {
    if (list[i] <= pivot)
      lower.push_back(list[i]);
    else
      upper.push_back(list[i]);
  }

  
  // recurse
  lower = qsort(lower);
  upper = qsort(upper);

  // copy it all back to list
  for (i=0;i<lower.size();i++){
    list[i] = lower[i];
  }
  list[i] = pivot;
  i++;
  for (int j = 0; j < upper.size() ; j++){
    list[i]=upper[j];
    i++;
  }
  return list;
  
}

void qsort2(std::vector<int> &a, int left, int right)
{
  int i = left, j = right;
  int tmp;
  int pivot;
  pivot = a[left];
  
  /* partition */
  while (i <= j) {
    while (a[i] < pivot)
      i++;
    while (a[j] > pivot)
      j--;
    if (i <= j) {
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		i++;
		j--;
      
	      }
	    }  
  if (left < j)
    qsort2(a, left, j);

  if (i< right)
    qsort2(a, i, right);
  
}


void print_help(std::string progname){
  std::cout << "Usage: " << progname << "[-p | -s N  | -a algorithm ]" << "\n";
  std::cout << "       " << "Algorithm s,m,q,2\n";
}

extern char *optarg;
int main(int argc, char *argv[])
{
  int i;
  int size=20;
  char algorithm = 's';
  bool print = false;
  char c;


  while ( (c = getopt(argc, argv,"ps:a:h")) != -1){
    switch(c){
    case 'h' :
      print_help(argv[0]);
      exit(0);
      break;
    case 'p':
      print = true;
      break;
    case 's':
      size = std::stoi(optarg);
      break;
    case 'a':
      algorithm = *optarg;
      break;
    }
  }

  std::vector<int> a(size);
  srand(time(NULL));
  for (i = 0; i < size; ++i) {
    a[i] = rand()%1000;
  }
  if (print)
    print_vector(a);

  std::cout << "Start!!\n";
  struct timeval tp;
  gettimeofday(&tp,NULL);
  long start_time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
  
  switch (algorithm){
  case 's':
    a = ssort(a);
    break;
  case 'm':
    a = msort(a);
    break;
  case 'q' :
    a = qsort(a);
    break;
  case '2':
    qsort2(a,0,a.size()-1);
    break;
  }
  gettimeofday(&tp,NULL);
  long current_time = tp.tv_sec * 1000 + tp.tv_usec / 1000;

  long elapsed = current_time - start_time;
  if (print)
    print_vector(a);
  std::cout << "time: " << elapsed << "\n";
  return 0;
}
