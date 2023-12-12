#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int possible_races(long t, long dist) {
  int total = 0;
  
  long speed;
  long d;

  for (long j = 0; j < t; j++) {
    speed = j;
    long x = t - speed;
    d = speed * x;
    if (d > dist) total += 1;
  }
  
  return total;
}


int main() {
  
  string line;
  string word;
  string num;
  string time = "";
  string distance = "";
  
  // read in file
  while(!cin.eof() && getline(cin, line)) {
    if (line == "") break;
    stringstream ss;
    ss << line;
    ss >> word;
    while(ss >> num) {
      if (word == "Time:") time += num;  
      if (word == "Distance:") distance += num;
    }
  }
  
  int n = possible_races(stol(time), stol(distance));
  
  cout << "Total Possible: " << n << endl;
  return 0;
}
