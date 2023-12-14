#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int predict(vector <int> nums) {
  int i;
  vector<vector<int>> tree;
  tree.push_back(nums);
  
  while (true) {
    vector <int> temp;
    int z = 0;
    for (i = 0; i < tree[tree.size()-1].size()-1; i++) {
      int diff = tree[tree.size()-1][i+1] - tree[tree.size()-1][i];
      if (diff == 0) z += 1;
      temp.push_back(diff);
    }
    if (z == temp.size()) {
      temp.push_back(0);
      tree.push_back(temp);
      break;
    } else {
      tree.push_back(temp);
    }
  }
   
  for (i = tree.size()-1; i > 0; i--) {
    int last = tree[i][0];
    int prev = tree[i-1][0];
    tree[i-1].insert(tree[i-1].begin(), prev-last);
  }

  return tree[0][0];
}


int main() {
  
  ifstream file;
  file.open("input.txt");
  string line;
  int num;
  long total = 0;
  
  while (getline(file, line)) {
    vector <int> temp;
    stringstream ss;
    ss << line;
    while (ss >> num) temp.push_back(num);
    total += (long)predict(temp);
  }
  
  cout << "TOTAL " << total << endl;
  return 0;

}
