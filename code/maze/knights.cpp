#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>



void print_board(int board[9][9]) {
  std::cout << "[0;0H\n";
  for (int i = 0; i < 9; i++){
    for (int j = 0;j < 9; j++){
      printf("%3d:",board[i][j]);
    }
    std::cout << "\n";
  }
}

void solve(int board[9][9],int row, int col, int step){


  if (step == 26){
    print_board(board);
    exit(0);
  }

  if (board[row][col]!=0)
    return;
      
  board[row][col]=step;
  //  usleep(80000);
  print_board(board);

  solve(board,row+1,col+2,step+1);
  solve(board,row+1,col-2,step+1);
  solve(board,row-1,col+2,step+1);
  solve(board,row-1,col-2,step+1);
  solve(board,row+2,col+1,step+1);
  solve(board,row+2,col-1,step+1);
  solve(board,row-2,col+1,step+1);
  solve(board,row-2,col-1,step+1);

  board[row][col]=0;
  }



int main()
{
  int board[9][9];
  int i,j;
  for (i = 0; i < 9; i++){
    for (j = 0; j < 9; j++){
      board[i][j]=-1;
    }
  }
  for (i = 2; i < 7; i++){
    for (j = 2; j < 7; j++){
      board[i][j]=0;
    }
  }
  
  

  std::cout << "[2J;\n";
  print_board(board);
  solve(board,3,3,1);
  std::cout << "Done!\n";
  return 0;
  
}
