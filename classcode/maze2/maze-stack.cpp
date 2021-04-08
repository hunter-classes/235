#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stack>
#include <queue>
std::string maze[30];
char me='Z';
char visited='.';
char wall=' ';
char goal='$';

void load_maze(std::string filename, std::string *maze){
  std::ifstream infile(filename);
  int i=0;
  while (std::getline(infile,maze[i])){
    i++;
  }
}

void print_maze(std::string maze[25]){
  std::cout << "[0;0H\n";
  for (int i = 0; i < 30; ++i) {
    std::cout << maze[i] << "\n";
  }

}

struct loc {
  int r,c;
};

void solve(std::string maze[30], int row, int col){
  //std::stack<struct loc> s;
  std::stack<struct loc> s;
  int r,c;
  struct loc l = {row,col};
  s.push(l);

  while (!s.empty()){
    l = s.top();
    s.pop();
    r = l.r;
    c = l.c;
    if (maze[r][c]=='$'){
      maze[r][c]='*';
      print_maze(maze);
      std::cout << "SOLVED!!!!!\n";
      return;
    }

    maze[r][c]='z';
    usleep(40000);
    print_maze(maze);
      maze[r][c] = '.';
    if (maze[r+1][c]=='#' || maze[r+1][c]=='$') {

      s.push({r:r+1,c:c});
    }
    if (maze[r-1][c]=='#'||  maze[r-1][c]=='$') {

      s.push({r:r-1,c:c});
    }
    if (maze[r][c+1]=='#' || maze[r][c+1]=='$') {

      s.push({r:r,c:c+1});
    }
    if (maze[r][c-1]=='#' ||  maze[r][c-1]=='$') {

      s.push({r:r,c:c-1});
    }
    
  }
  
  

  }
  
  

int main()
{
  int solved=0;
  
  //load_maze("maze.dat",maze);
  //solve(maze,1,2);
  load_maze("maze2.dat",maze);
  solve(maze,28,26);
  return 0;
}

