#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

char me='Z';
char wall=' ';
char goal='$';
char visited='.';

int load_maze(std::string filename, std::string *maze){
  std::ifstream infile(filename);
  int i=0;
  while(std::getline(infile,maze[i])){
    i++;
  }
  return i;
}


void print_maze(std::string maze[], int lines){
  std::cout << "[0;0H\n";
  for (int i = 0; i < lines; ++i) {
    std::cout << maze[i] << "\n";
  }
}

void solve(std::string maze[], int lines, int row, int col, bool &solved){
  // check for base cases
 
  // we can't go any further along this path
  // we hit a wall or ourselves
  char current = maze[row][col];
  if (current == wall || current == me){
    return;
  }

  // we don't want to go further because we found the goal
  if (current == goal){
    solved = true;
    return;
  }

  maze[row][col] = me;
  usleep(80000);
  print_maze(maze,lines);

  // try to solve the maze by calling the solve routine
  // (this routine) but from a new location. Call it once for each
  // possible direction
  if (!solved) solve(maze,lines,row-1,col, solved);
  if (!solved) solve(maze,lines,row+1,col, solved);
  if (!solved) solve(maze,lines,row,col-1, solved);
  if (!solved) solve(maze,lines,row,col+1, solved);

  if (!solved) maze[row][col]=visited;
  
}

int main(int argc, char *argv[])
{
  std::string maze[27];
  int lines;
  lines = load_maze("maze.dat",maze);
  print_maze(maze,lines);
  bool solved = false;
  solve(maze,lines,1,1,solved);

    
  return 0;
}
