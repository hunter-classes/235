#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

char me='Z';
char wall=' ';
char goal='$';
char path='#';
char visited='.';

int load_maze(std::string filename, std::string *maze){
  std::ifstream infile(filename);
  int i=0;
  while(std::getline(infile,maze[i])){
    i++;
  }
  return i;
}

void print_maze(std::string maze[],int lines){
  std::cout << "[0;0H\n";
  for(int i = 0; i < lines; i++){
    std::cout << maze[i] << "\n";
  }
}

void solve(std::string maze[], int lines, int row, int col, bool &solved){
  if (maze[row][col]==goal){
    solved = true;
    return;
  }
  if (maze[row][col]==wall ||
      maze[row][col]==me |
      maze[row][col]==visited){
    return;
  }

  maze[row][col]=me;
  usleep(80000);
  print_maze(maze,lines);
  
  if (!solved) solve(maze,lines,row-1,col,solved);
  if (!solved) solve(maze,lines,row+1,col,solved);
  if (!solved) solve(maze,lines,row,col-1,solved);
  if (!solved) solve(maze,lines,row,col+1,solved);
  
  if (!solved) maze[row][col]=visited;
}


int main()
{
  std::string maze[27];
  int lines;
  lines = load_maze("maze.dat",maze);

  std::cout << "[2J;\n";
  print_maze(maze,lines);
  bool solved = false;
  solve(maze,lines,2,2,solved);
  print_maze(maze,lines);
  std::cout << "Done!\n";
  return 0;
  
}
