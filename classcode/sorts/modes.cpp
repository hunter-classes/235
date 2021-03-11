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

  // this loop is O(n)
  for(int i = 1 ; i < v.size();i++){
    // freq is another loop through the data so this is anotehr O(n)
    // even though it looks like just one function call 
    int current = freq(v,v[i]);
    if (current > mode_count_so_far){
      mode_so_far = v[i];
      mod_i = i;
    }
    
  }

  // O(n^2) 
  return mode_so_far;
}

int mode2(std::vector<int> v){

  // O(n)
  int max_val = 0;
  for (auto i :  v){
    if (i>max_val){
      max_val = i;
    }
  }

  std::vector<int> counts(max_val+1);

  // O(n)
  for (auto i : v){
    counts[i]++;
  }

  int mode_i = 0;
  // O(n) ???? <-- nope, it's O(m) where m is the max_val+1 or in many cases
  // it will be constant O(k)
  for (int i = 0 ; i < max_val+1 ; i++)
    if (counts[i] > counts[mode_i]){
      mode_i = i;
    }


  // overall -> O(n) + O(n) +k = O(2n)+k 
  return mode_i;

}


void print_vector(std::vector<int> a){
  for (auto i : a) {
    std::cout << i << ", ";
    
  }

  std::cout << "\n";
  
}

void print_help(char *command_name){
  std::cout << "Usage: " << command_name << " etc.\n";
  
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
  int m;
  gettimeofday(&tp,NULL);
  long start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;
  if (algorithm == '1'){
    m = mode1(a);
    std::cout << "mode1: " << m << "\n";
  } else if (algorithm == '2'){
    m = mode2(a);
    std::cout << "mode2: " << m << "\n";
  } else if (algorithm == '3'){
    m = mode1(a);
    std::cout << "mode1: " << m << "\n";
    m = mode2(a);
    std::cout << "mode2: " << m << "\n";
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
