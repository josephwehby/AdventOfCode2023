#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// read in line as string stream and store in vector
vector <long> read_nums(stringstream &ss) {
  long num;
  vector <long> vals;
  while (ss >> num) vals.push_back(num);

  return vals;
}

// find location
long find_location(long seed, vector<vector<long>> &mappings) {
  long c = seed; 
  for (vector <long> m : mappings) {
    for (int i = 0; i < m.size(); i+=3) {
      long d = m[i];
      long s = m[i+1];
      long r = m[i+2];

      if (s <= c && c < (s+r)) {
        c = d + (c-s);
        break;
      }
    }
  }
  return c;
} 

int main() {
  
  string line;
  string word;
  vector <long> seeds;
  vector<vector<long>> mappings;
  stringstream ss; 
  
  mappings.resize(7);

  // get seeds
  getline(cin, line);
  ss << line;
  ss >> word;
  seeds = read_nums(ss);
  getline(cin, line);
  
  int index = 0;

  // get mappings
  while (getline(cin, line)) {
    while (getline(cin, line)) {
      if (line == "") break;
      
      stringstream nums; 
      vector <long> temp;
      nums << line;
      temp = read_nums(nums);  
      for (long num : temp) mappings[index].push_back(num);
    
    }
    index++;
  }
  
  long total = 2104769314;
  long count = 0;
  long min = 9223372036854775807; 
  
  cout << "Seed Pairs: " << seeds.size()/2 << endl;
  
  for (int i = 0; i < seeds.size(); i+=2) {
    for (long n = seeds[i]; n < (seeds[i] + seeds[i+1]); n++) {
      long pos = find_location(n, mappings);
      if (pos < min) min = pos;
      if (count % 75000 == 0) cout << "Pair " << i << " Percent Complete " << count << "/" << total << "\r";
      count += 1;
    }
  }
  cout << endl;
  cout << total << endl;
  cout << "Minimum: " << min << endl;
  return 0;
}
