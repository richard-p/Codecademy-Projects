#include <iostream>
#include <string>
#include <vector>
#include "ttt_func.h"

int main(){
  int winner = -1; // 1 is x, 0 is o
  char tile;
  int pos = 0;
  int idx;
  int turn = 0;
  std::vector<char> r1 = {' ', '|', ' ', '|', ' '};
  std::vector<char> r2 = {' ', '|', ' ', '|', ' '};
  std::vector<char> r3 = {' ', '|', ' ', '|', ' '};

  while (winner == -1){
    std::cout << "What tile to place (x or o): ";
    std::cin >> tile;

    std::cout << "What position to place (1-9): ";
    std::cin >> pos;

    idx = locate_tile(tile, pos);
    if (idx < 0){std::cout << "Invalid Input\n";}
    if (pos <= 3){
        
        r1[idx] = tile;

      } else if (pos > 3 && pos <= 6){
        
        r2[idx] = tile;
      
      } else {
        
        r3[idx] = tile;
      
      }

    turn++;

    // check if winner
    // minimum 5 turns before there can be a winner
    // winning moves:
    /*
    r1[0], r2[2], r3[4] diag
    r1[4], r2[2], r3[0] diag
    r1[0], r1[2], r1[4] -
    r2[0], r2[2], r2[4] -
    r3[0], r3[2], r3[4] -
    r1[0], r2[0], r3[0] |
    r1[2], r2[2], r3[2] |
    r1[4], r2[4], r3[4] |
    */
    if (turn >= 5){
      winner = checkWinner(r1, r2, r3);
      if (winner == 1) {std::cout << "X wins!\n";}
      if (winner == 0) {std::cout << "O wins!\n";}
    }
    if (turn >= 10){
      std::cout << "probably a tie...\n";
    }

    display_board(r1, r2, r3);
  }

}