#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>


std::string maze[27];
char me='Z';
char wall='#';
char goal='$';


void load_maze(std::string filename, std::string *maze){
  std::ifstream infile(filename);
  int i=0;
  while(std::getline(infile,maze[i])){
    i++;
  }
}

void print_maze(std::string maze[27]){
  std::cout << "[0;0H\n";
  for (int i=0; i < 25;  ++i) {
    std::cout << maze[i] << "\n";
  }
}


int main()
{
  load_maze("maze.dat",maze);
  print_maze(maze);
  
  return 0;
}
