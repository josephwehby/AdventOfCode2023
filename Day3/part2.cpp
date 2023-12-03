#include <iostream>
#include <vector>

using namespace std;

int check_symbol(vector<vector<char>>& grid, int row, int col) {
  
  int num_cols = grid[0].size();

  if (row-1 >= 0 && grid[row-1][col] != '.' && grid[row-1][col] == '*') {
    return ((row-1)*num_cols + col);
  };
  if (row+1 < grid.size() && grid[row+1][col] != '.' && grid[row+1][col] == '*') {
    return ((row+1)*num_cols + col);
  }
  if (col-1 >= 0 && grid[row][col-1] != '.' && grid[row][col-1] == '*') {
    return ((row)*num_cols + col-1);
  }
  if (col+1 < grid[0].size() && grid[row][col+1] != '.' && grid[row][col+1] == '*') { 
    return ((row)*num_cols + col+1);
  }
  if (row-1 >= 0 && col-1 >= 0 && grid[row-1][col-1] != '.' && grid[row-1][col-1] == '*') {
    return ((row-1)*num_cols + col-1);
  }
  if (row-1 >= 0 && col+1 < grid.size() && grid[row-1][col+1] != '.' && grid[row-1][col+1] == '*') {
    return ((row-1)*num_cols + col+1);
  }
  if (row+1 < grid.size() && col-1 >= 0 && grid[row+1][col-1] != '.' && grid[row+1][col-1] == '*') {
    return ((row+1)*num_cols + col-1);
  }
  if (row+1 < grid.size() && col+1 < grid[0].size() && grid[row+1][col+1] != '.' && grid[row+1][col+1] == '*') {
    return ((row+1)*num_cols + col+1);
  }
  
  return 0;
}



int main() {
  vector<vector<char>> grid;
  
  // read in grid
  string line;
  while (getline(cin, line)) {
    vector <char> temp;
    for (char c : line) {
      temp.push_back(c);
    }
    grid.push_back(temp);
  }
  
  int total = 0;
  vector<vector<int>> stars;

  stars.resize(grid.size()*grid[0].size());

  // find potential part numbers
  for (int row = 0; row < grid.size(); row++) {
    string current_num = "";
    int valid = 0; 
    for (int col = 0; col < grid[row].size(); col++) {
      if (isdigit(grid[row][col])) {
        current_num += grid[row][col];
        int p = check_symbol(grid, row, col);
        if (p != 0) valid = p;
      
      } else {
        if (current_num != "") {
          if (valid > 0 ) {
            cout << current_num << endl;
            stars[valid].push_back(stoi(current_num));
          }
          current_num = "";
          valid = 0;
        } 
        current_num = "";
      }
      if (current_num != "" && col == grid[row].size()-1) {
        if (valid > 0 ) {
          cout << current_num << endl;
          stars[valid].push_back(stoi(current_num));
         }
      }
    }
  }

  for (int i = 0; i < stars.size(); i++) {
    if (stars[i].size() == 2) {
      total += (stars[i][0] * stars[i][1]);
    }
  }
  cout << "TOTAL: " << total << endl;
  return 0;
}
