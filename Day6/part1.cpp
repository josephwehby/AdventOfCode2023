#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int possible_races(int t, int dist) {
  int total = 0;
  
  int speed;
  int d;

  for (int j = 0; j < t; j++) {
    speed = j;
    int x = t - speed;
    d = speed * x;
    if (d > dist) total += 1;
  }
  
  return total;
}


int main() {
  
  string line;
  string word;
  int num;
  vector <int> time;
  vector <int> distance;
  
  // read in file
  while(!cin.eof() && getline(cin, line)) {
    if (line == "") break;
    stringstream ss;
    ss << line;
    ss >> word;
    while(ss >> num) {
      if (word == "Time:") time.push_back(num);  
      if (word == "Distance:") distance.push_back(num);
    }
  }
  
  int product = 1;
  for (int i = 0; i < time.size(); i++) {
    int n = possible_races(time[i], distance[i]);
    product *= n;
  }
  
  cout << "Total Possible: " << product << endl;
  return 0;
}
