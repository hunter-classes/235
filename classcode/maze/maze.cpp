#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>


std::string maze[27];
char me='Z';
char wall=' ';
char goal='$';
char visited='.';


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

void solve(std::string maze[26], int row, int col,int &solved){
  usleep(40000);
  char current = maze[row][col];
  if (current == visited || current == me || current == wall) {
    return;
  }

  if (current == goal){
    solved = 1;
    return;
  }
  maze[row][col]=me;
  print_maze(maze);

  if (!solved) {solve(maze,row-1,col,solved);}
  if (!solved) {solve(maze,row+1,col,solved);}
  if (!solved) {solve(maze,row,col+1,solved);}
  if (!solved) {solve(maze,row,col-1,solved);}
  if (!solved) {maze[row][col]=visited;}
  
}

int main()
{
  int solved = 0;
  load_maze("maze.dat",maze);
  print_maze(maze);
  solve(maze,1,1,solved);
  return 0;
}
