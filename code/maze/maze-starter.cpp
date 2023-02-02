#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

int load_maze(std::string filename, std::string *maze) {
  std::ifstream infile(filename);
  int i=0;
  while(std::getline(infile,maze[i])){
      i++;
    }
  return i;
}

void print_maze(std::string maze[], int lines){
  std::cout << "[0;0H\n";

  for (int i=0; i < lines; i++){
    std::cout << maze[i] << "\n";
  }
  
}



int main()
{
  std::string maze[27];
  int lines;
  bool solved = false;
  
  lines = load_maze("maze.dat",maze);
  usleep(80000);

  print_maze(maze,lines);
//   solve(maze,lines,2,2,solved);
  return 0;
}
    
