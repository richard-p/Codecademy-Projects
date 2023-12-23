#include <iostream>
#include <string>
#include <vector>
void display_board(std::vector<char> row1, std::vector<char> row2, std::vector<char> row3){
  for (int i=0; i < row1.size(); i++){
    std::cout << row1[i];
  }
  std::cout << "\n";
  std::cout << "-----\n";
  for (int i=0; i < row2.size(); i++){
    std::cout << row2[i];
  }
  std::cout << "\n";
  std::cout << "-----\n";
  for (int i=0; i < row3.size(); i++){
    std::cout << row3[i];
  }
  std::cout << "\n";
}

bool check_valid_input(char in1, int in2){
  if (in1 == 'x' || in1 == 'o'){
    for (int i=1; i<=9; i++){
      if (in2 == i){
        return true;
      }
    }
  }

  return false;
}

int ugly_mapping(int position){
  int ans;
  switch (position % 3){
    case 1:
      ans = 0;
      break;
    case 2:
      ans = 2;
      break;
    case 0:
      ans = 4;
      break;
  }

  return ans;
}

int locate_tile(char xotile, int position){
  int i;
  if (check_valid_input(xotile, position)){
    // figure out where to put it
    i = ugly_mapping(position);
  } else {
    return -1;
  }
  return i;
}

int checkWinner(std::vector<char> row1, std::vector<char> row2, std::vector<char> row3){
  if (row1[0] == row2[0] && row2[0] == row3[0]){
    
    if (row1[0] == 'x'){return 1;}
    else {return 0;}

  } else if (row1[2] == row2[2] && row2[2] == row3[2]){
    
    if (row1[2] == 'x'){return 1;}
    else {return 0;}

  } else if (row1[4] == row2[4] && row2[4] == row3[4]){
    
    if (row1[4] == 'x'){return 1;}
    else {return 0;}

  } else if (row1[0] == row1[2] && row1[2] == row1[4]){
    
    if (row1[0] == 'x'){return 1;}
    else {return 0;}

  } else if (row2[0] == row2[2] && row2[2] == row2[4]){
    
    if (row2[0] == 'x'){return 1;}
    else {return 0;}

  } else if (row3[0] == row3[2] && row3[2] == row3[4]){
    
    if (row3[0] == 'x'){return 1;}
    else {return 0;}

  } else if (row1[0] == row2[2] && row2[2] == row3[4]){
    
    if (row1[0] == 'x'){return 1;}
    else {return 0;}

  } else if (row1[4] == row2[2] && row2[2] == row3[0]){
    
    if (row1[4] == 'x'){return 1;}
    else {return 0;}

  } else {
    return -1;
  }
}

