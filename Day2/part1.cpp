#include <iostream>
#include <sstream>

using namespace std;

int main () {
  
  const int red = 12;
  const int green = 13;
  const int blue = 14;
  
  string line;
  int total = 0;

  while (getline(cin, line)) {
    
    cout << line << endl;
    stringstream ss;
    ss << line;
    
    string prev = "";
    int id;
    bool valid = true;
    while (ss && valid) {
      
      string temp;
      ss >> temp;
      
      // get id
      if (prev == "Game") {
        temp.pop_back();
        id = stoi(temp);
      } else {

        // get number
        stringstream num_convert;
        num_convert << temp;
        int val;
        num_convert >> val;
      
        if (!num_convert.fail()) {
          cout << val << endl;
          string color;
          ss >> color;
        
          if (!ss.eof()) color.pop_back();
        
          cout << color << endl;
          if (color == "red" && val > red) valid = false;
          if (color == "green" && val > green) valid = false;
          if (color == "blue" && val > blue) valid = false;
        }
      }

      prev = temp;
      
    }

    if (valid == true) total += id;
    
  }

  cout << "TOTAL: " << total << endl;
  
  return 0;
}
