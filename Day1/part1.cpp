#include <iostream>

using namespace std;

int main() {
	
	string line;
	int total = 0;

	while (getline(cin, line)) {
    int left = -1;
    int right = -1;

    for (char c : line) {
      if (isdigit(c) && left == -1) {
        left = c - '0';
        right = c - '0';
      } else if (isdigit(c)){
        right = c - '0';
      } else {}
    }
    int num = left*10 + right;
    cout << line << endl;
    cout << num << endl;
	  total += num;
  }
  cout << "TOTAL " << total << endl;
	return 0;
}
