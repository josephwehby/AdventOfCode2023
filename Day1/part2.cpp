#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int check_map(map <string,int>& nums, string potential, bool flip) {
  if (flip == true) reverse(potential.begin(), potential.end());

  for (auto mit = nums.begin(); mit != nums.end(); mit++) {
    if (potential.find(mit->first) != string::npos) return mit->second;
  }
  return -1;
}

int find_num(string& line, map<string, int>& nums, bool flip) {
  string potential = "";
  int left = -1;
  
  for (char c : line) {

    if (isdigit(c)) {
        left = c - '0';
        return left;
    } else {
      potential += c;
      int check = check_map(nums, potential, flip);
      if (check != -1) {
          left = check;
          return left;
      }
    }
  }

  return -1;
}




int main() {
	
	string line;
	int total = 0;
  map <string, int> nums;
  
  nums["one"] = 1;
  nums["two"] = 2;
  nums["three"] = 3;
  nums["four"] = 4;
  nums["five"] = 5;
  nums["six"] = 6;
  nums["seven"] = 7;
  nums["eight"] = 8;
  nums["nine"] = 9;

  
	while (getline(cin, line)) {
    int left = -1;
    int right = -1;
    string potential = "";
    
    cout << line << endl;
    
    // find left
    left = find_num(line, nums, false);
    
    // find right
    reverse(line.begin(), line.end());

    right = find_num(line, nums, true);
    

    int num = left*10 + right;
    total += num;
    cout << num << endl;
  
  }

  cout << "TOTAL " << total << endl;
	return 0;
}
