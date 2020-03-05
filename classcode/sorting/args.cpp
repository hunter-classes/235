#include <iostream>

int main(int argc, char *argv[])
{
  std::cout << argc << "\n"; 

  for (int i = 0; i < argc; ++i) {
    std::cout << "argv[" << i << "] : " << argv[i] << "\n";
  }


  return 0;
  
}
