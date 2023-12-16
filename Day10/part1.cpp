#include <iostream>
#include <vector>
#include <fstream>
#include <deque>

using namespace std;

struct Node {
  int row;
  int col;
  char c;
  bool visted = false;
  vector <Node *> edges;
};

class Maze {
  public:
    Maze (string);
    ~Maze();
    void build_grid();
    void connect_grid();
    void print_grid();
    int bfs();
  private:
    bool check_dir(int, int);
    vector<vector<Node*>> grid;
    Node * start;  
    string file;
};

Maze::Maze(string file) {
  this->file = file;
}

Maze::~Maze() {
  for (auto v : grid) {
    for (auto n : v) if (n != NULL) delete n;
  }
}

void Maze::build_grid() {
  ifstream f;
  string line;
  f.open(file);
  
  int row, col;
  row = 0;

  while (getline(f, line)) {
   col = 0;
   vector <Node *> temp;
   for (char c : line) {
    Node *n = new Node;
    n->row = row;
    n->col = col;
    n->c = c;
    col++;
    temp.push_back(n);
   }
   grid.push_back(temp);
   row++;
  }
}

// very very very ulgy function but it works
void Maze::connect_grid() {
  
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[row].size(); col++) {
      Node *n = grid[row][col];
      if (n->c == 'S') {
        start = n;
        if (check_dir(row-1, col) && (grid[row-1][col]->c == '7' || grid[row-1][col]->c == 'F' || grid[row-1][col]->c == '|')) n->edges.push_back(grid[row-1][col]);     
        if (check_dir(row+1, col) && (grid[row+1][col]->c == 'L' || grid[row+1][col]->c == 'J' || grid[row+1][col]->c == '|')) n->edges.push_back(grid[row+1][col]);     
        if (check_dir(row, col-1) && (grid[row][col-1]->c == 'L' || grid[row][col-1]->c == 'F')) n->edges.push_back(grid[row][col-1]);     
        if (check_dir(row, col+1) && (grid[row][col+1]->c == '-' || grid[row][col+1]->c == 'J' || grid[row][col+1]->c == '7')) n->edges.push_back(grid[row][col+1]);     
      }
      if (n->c == '.') continue;
      if (n->c == '-') {
        if (check_dir(row, col+1)) n->edges.push_back(grid[row][col+1]);
        if (check_dir(row, col-1)) n->edges.push_back(grid[row][col-1]);
      } else if (n->c == '|') {
        if (check_dir(row+1, col)) n->edges.push_back(grid[row+1][col]);
        if (check_dir(row-1, col)) n->edges.push_back(grid[row-1][col]);
      } else if (n->c == 'L') {
        if (check_dir(row-1, col)) n->edges.push_back(grid[row-1][col]);
        if (check_dir(row, col+1)) n->edges.push_back(grid[row][col+1]);
      } else if (n-> c == 'J') {
        if (check_dir(row, col-1)) n->edges.push_back(grid[row][col-1]);
        if (check_dir(row-1, col)) n->edges.push_back(grid[row-1][col]);
      } else if (n->c == '7') {
        if (check_dir(row+1, col)) n->edges.push_back(grid[row+1][col]);
        if (check_dir(row, col-1)) n->edges.push_back(grid[row][col-1]);
      } else if (n->c == 'F') {
        if (check_dir(row, col+1)) n->edges.push_back(grid[row][col+1]);
        if (check_dir(row+1, col)) n->edges.push_back(grid[row+1][col]);
      }
    }
  }
}

bool Maze::check_dir(int row, int col) {
  if (row >= 0 && row < grid.size() && col >= 0 && col <= grid[0].size()) return true;
  return false;
}

int Maze::bfs() {
  deque<Node *> q;
  vector <int> d;
  q.push_back(start);
  d.resize(grid.size()*grid[0].size(), 0);

  while(!q.empty()) {
    auto n = q[0];

    for (auto adj : n->edges) {
      if (adj->visted == false) {
        d[adj->col * grid[0].size() + adj->row] = d[n->col*grid[0].size() + n->row] + 1;
        adj->visted = true;
        q.push_back(adj);
      }
    }

    n->visted = true;
    q.pop_front();
  }

  int max = 0;
  for (auto i : d) {
    if (i > max) max = i;
  }

  return max;
}

void Maze::print_grid() {
  for (auto v : grid) {
    for (auto n : v) {
      cout << "ROW: " << n->row << " COL: " << n->col;
      cout << " LETTER: " << n->c << ": ";
      for (auto d : n->edges) {
        cout << d->c << " ";
      }
      cout << endl;
    }
  }
}

int main() {

  Maze m("input.txt");
  m.build_grid();
  m.connect_grid();
 // m.print_grid();
  cout << m.bfs() << endl;
  return 0;
}
