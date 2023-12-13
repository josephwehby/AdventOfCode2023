#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int search(map<string, vector<string>>& grid, string order) {
  
  int steps = 0;
  int index = 0;
  int length = order.size()-1;
  string current = "AAA";

  while (true) {
    int direction = (order[index] == 'L') ? 0 : 1; 
    current = grid[current][direction];
    steps++;
    if (current == "ZZZ") return steps;
    index = (index+1 > length) ? 0 : index+1;
  }
  return steps;
}

int main() {
  ifstream file("input.txt");
  string line;
  string order;

  getline(file, order);
 
  map<string, vector<string>> grid;
  
  while (getline(file, line)) {
    string word = "";
    string node, left, right;
    for (char c : line) {
      if (c == ' ' || c == '(') continue;
      
      if (c == '=') {
        node = word;
        word = "";
        continue;
      } else if (c == ',') {
        left = word;
        word = "";
        continue;
      } else if (c == ')') {
        right = word;
        break;
      }
      word += c;
    }
    grid[node].push_back(left);
    grid[node].push_back(right);
  }

  // print grid
  for (auto m = grid.begin(); m != grid.end(); m++) {
    cout << m->first << " ";
    for (string s : m->second) cout << s << " ";
    cout << endl;
  }
  cout << search(grid, order) << endl;
  return 0;
}
