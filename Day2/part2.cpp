#include <iostream>
#include <sstream>

using namespace std;

int main () {
  
  
  string line;
  int total = 0;

  while (getline(cin, line)) {
    
    cout << line << endl;
    stringstream ss;
    ss << line;
     
    string prev = "";
    int id;
    
    int max_red = 0;
    int max_blue = 0;
    int max_green = 0;

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
          if (color == "red" && val > max_red) max_red = val;
          if (color == "green" && val > max_green) max_green = val;
          if (color == "blue" && val > max_blue) max_blue = val;
        }
      }

      prev = temp;
      
    }

    total += (max_red * max_green * max_blue);
    
  }

  cout << "TOTAL: " << total << endl;
  
  return 0;
}
