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

void solve(std::string maze[], int lines, int row, int col){
  // check the base cases

  // base case 1are we at the exit?
  if (maze[row][col]==goal){
    return;
  }

  if (maze[row][col]==wall){
    return;
  }

  
  // add me at row col to the maze
  maze[row][col]=me;
  print_maze(maze,lines);
  
  // recusively try to solve by stepping once
    // in each of the four drections.

  
}


int main()
{
  std::string maze[27];
  int lines;
  lines = load_maze("maze.dat",maze);
  print_maze(maze,lines);
  solve(maze,lines,2,2);
  return 0;
}
