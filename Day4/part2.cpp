#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  
  string line;
  int total = 0;
  int line_num = 0;
  vector <int> wins;
  wins.resize(200,0);

  while (getline(cin, line)) {
    
    string current = "";
    int index = 0;
    wins[line_num] += 1;
    
    // get index of information
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == ':') {
        index = i;
        break;
      }
    }
    
    // turn first half into a map
    map <string, int> counts;
    for (int i = index; i < line.size(); i++) {
      if (isdigit(line[i])) {
        current += line[i];
      } else if (line[i] == '|'){
        index = i + 1;
        current = "";
        break;
      } else {
        if (current != "") {
          cout << current << " ";
          counts[current] = 0;
        }
        current = "";
      }
    }
    
    // check for matches
    cout << " | ";
    for (int i = index; i < line.size(); i++) {
      if (isdigit(line[i])) {
        current += line[i];
        if (i == line.size()-1) {
          if (counts.find(current) != counts.end()) {
            cout << current << " ";
            counts[current] += 1;
          }
        }
      } else {
        if (counts.find(current) != counts.end()) {
          cout << current << " ";
          counts[current] += 1;
        }
        current = "";
      }
    }
    
    int matches = 0;
    for (auto mit = counts.begin(); mit != counts.end(); mit++) {
      if (mit->second > 0) matches += 1;
    }
    cout << "MATCHES " << matches << endl;
    
    for (int i=0; i < matches; i++) {
      wins[i+line_num+1] += wins[line_num];
    }
    
    line_num += 1;
  }

  for (int j : wins) total += j;

  cout << "Wins: " << total << endl;
  return 0;
}
