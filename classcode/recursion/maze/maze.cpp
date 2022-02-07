#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

char me='Z';
char wall=' ';
char goal='$';

int load_maze(std::string filename, std::string *maze){
  std::ifstream infile(filename);
  int i=0;
  while(std::getline(infile,maze[i])){
    i++;
  }
  return i;
}

void print_maze(std::string maze[],int lines){
  for(int i = 0; i < lines; i++){
    std::cout << maze[i] << "\n";
  }
}

int main()
{
  std::string maze[27];
  int lines;
  lines = load_maze("maze.dat",maze);
  print_maze(maze,lines);
  
  return 0;
}
