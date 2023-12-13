#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Hand {
  string cards;
  string hand_type;
  int value;
};

map <string, vector<Hand*>> hands;

Hand* process_hand(string c) {
  
  if (c == "") return NULL;

  stringstream ss;
  string first, second;
  Hand* h = new Hand;
  map <char, int> cards;
  
  ss << c;
  ss >> first;
  ss >> second;

  h->cards = first; 
  h->value = stoi(second);

  // get count of each card
  for (char b : first) {
    auto mit = cards.find(b);
    if (mit != cards.end()) {
      cards[b] += 1;
    } else {
      cards[b] = 1;
    }
  }
  
  // get hand type
  if (cards.size() == 1) h->hand_type = "FIVE";
  if (cards.size() == 4) h->hand_type = "ONE_PAIR"; 
  if (cards.size() == 5) h->hand_type = "HIGH";
  
  if (cards.size() == 2) {
    h->hand_type = "FULL";
    for (auto m = cards.begin(); m != cards.end(); m++) {
      if (m->second == 4) {
        h->hand_type = "FOUR_OF_KIND";
      }
    }
  }
  
  if (cards.size() == 3) {
    h->hand_type = "TWO_PAIR";
    for (auto m = cards.begin(); m != cards.end(); m++) {
      if (m->second == 3) {
        h->hand_type = "THREE_OF_KIND";
      }
    }
  }
  hands[h->hand_type].push_back(h);
  return h;
}

int main() {
  
  // read in the file
  string line;
  map<char, int> mappings = {{'A',14}, {'K',13}, {'Q',12}, {'J',11}, {'T',10}};

  ifstream file("input.txt");
  int rank = 0;
  while(getline(file, line)) {
    Hand* h = process_hand(line);
    rank++;
  }
  for (auto m = hands.begin(); m != hands.end(); m++) {
    sort(m->second.begin(), m->second.end(), 
    [&mappings](Hand *first, Hand *second)
    {
      string hand_one = first->cards;
      string hand_two = second->cards;
      int num1;
      int num2;

      for (int i = 0; i < hand_one.size(); i++) {
        auto m1 = mappings.find(hand_one[i]);
        auto m2 = mappings.find(hand_two[i]);
        
        int num1 = (m1 != mappings.end()) ? m1->second : int(hand_one[i] - '0');
        int num2 = (m2 != mappings.end()) ? m2->second : int(hand_two[i] - '0');
        
        
        if (num1 > num2) return true;
        if (num1 < num2) return false;
      }

      return true;
    }
    );
  }
  
  long total = 0;
  string order[7] = {"FIVE", "FOUR_OF_KIND", "FULL", "THREE_OF_KIND", "TWO_PAIR", "ONE_PAIR", "HIGH"};
  for (int i = 0; i < 7; i++) {
    auto t = hands.find(order[i]); 
    for (Hand *j : t->second) {
      cout << j->cards << endl;
      total += (long)(j->value * rank);
      delete j;
      rank--;
    }
  }
  cout << "TOTAL " << total << endl;
  return 0;
}
