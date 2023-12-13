#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

long long search(map<string, vector<string>>& grid, string order) {
  
  int steps = 0;
  int index = 0;
  int length = order.size()-1;
  string current;
  vector <string> nodes;

  for (auto m = grid.begin(); m != grid.end(); m++) {
    if (m->first[2] == 'A') nodes.push_back(m->first);
  }

  vector <int> step_counts;

  for (string node : nodes) {
    steps = 0;
    index = 0;
    while (true) {
      int direction = (order[index] == 'L') ? 0 : 1; 
      node = grid[node][direction];
      steps++;
      if (node[2] == 'Z') {
        step_counts.push_back(steps);
        break;
      }
      index = (index+1 > length) ? 0 : index+1;
    }
  }
  
  long long res = lcm(step_counts[0], step_counts[1]);
  for (size_t i = 2; i < step_counts.size(); i++) {
    res = std::lcm(res, step_counts[i]);
  }
  return res;
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
