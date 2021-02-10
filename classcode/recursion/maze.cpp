#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

std::string maze[27];

int load_maze(std::string filename, std::string *maze){
  std::ifstream infile(filename);
  int i=0;
  while(std::getline(infile,maze[i])){
    i++;
  }
  return i;
}



int main(int argc, char *argv[])
{
  int lines;
  lines = load_maze("maze.dat",maze);
  
  
  for (int i = 0; i < lines ; i ++){
    std::cout << maze[i] << "\n";
    
  }
  std::cout << "\n";

    
  return 0;
}
