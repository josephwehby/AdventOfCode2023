#include <iostream>
#include <vector>

using namespace std;

int check_symbol(vector<vector<char>>& grid, int row, int col) {
  // check up
  if (row-1 >= 0 && grid[row-1][col] != '.' && !isalpha(grid[row-1][col]) && !isdigit(grid[row-1][col])) return 1;
  // check down
  if (row+1 < grid.size() && grid[row+1][col] != '.' && !isalpha(grid[row+1][col]) && !isdigit(grid[row+1][col])) return 1;
  //check left
  if (col-1 >= 0 && grid[row][col-1] != '.' && !isalpha(grid[row][col-1]) && !isdigit(grid[row][col-1])) return 1;
  // check right
  if (col+1 < grid[0].size() && grid[row][col+1] != '.' && !isalpha(grid[row][col+1]) && !isdigit(grid[row][col+1])) return 1;
  
  // check diagonals
  if (row-1 >= 0 && col-1 >= 0 && grid[row-1][col-1] != '.' && !isalpha(grid[row-1][col-1]) && !isdigit(grid[row-1][col-1])) return 1;
  if (row-1 >= 0 && col+1 < grid.size() && grid[row-1][col+1] != '.' && !isalpha(grid[row-1][col+1]) && !isdigit(grid[row-1][col+1])) return 1;
  if (row+1 < grid.size() && col-1 >= 0 && grid[row+1][col-1] != '.' && !isalpha(grid[row+1][col-1]) && !isdigit(grid[row+1][col-1])) return 1;
  if (row+1 < grid.size() && col+1 < grid[0].size() && grid[row+1][col+1] != '.' && !isalpha(grid[row+1][col+1]) && !isdigit(grid[row+1][col+1])) return 1;

  return 0;
}

int main() {
  vector<vector<char>> grid;
  
  string line;
  while (getline(cin, line)) {
    vector <char> temp;
    for (char c : line) {
      temp.push_back(c);
    }
    grid.push_back(temp);
  }
  
  int total = 0;

  for (int row = 0; row < grid.size(); row++) {
    
    string current_num = "";
    int valid = 0;
    
    for (int col = 0; col < grid[row].size(); col++) {
      
      if (isdigit(grid[row][col])) {
        current_num += grid[row][col];
        valid += check_symbol(grid, row, col);
      
      } else {
        
        if (current_num != "") {
          if (valid > 0 ) {
            cout << current_num << endl;
            total += stoi(current_num);
          }
          current_num = "";
          valid = 0;
        }
        
        current_num = "";
      }

      if (current_num != "" && col == grid[row].size()-1) {
        if (valid > 0 ) {
          cout << current_num << endl;
          total += stoi(current_num);
         }
      }
    }
  }
  cout << "TOTAL: " << total << endl;
  return 0;
}
