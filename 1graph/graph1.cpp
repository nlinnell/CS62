#include <vector>
#include <set>
#include <cassert>

using namespace std;

class Graph {
public:
  // create an empty graph
  Graph() {}

  void addVertex() {  // add a new vertex
    adjLists.push_back(std::set<int>());
  }
  void addEdge(int i, int j) {  // add an edge between ith and jth vertex
    assert(i<n() &&j<n());//precondition
    adjLists[i].insert(j);
    adjLists[j].insert(i);
  }
  bool areAdjacent(int i, int j) {
    assert(i<n() &&j<n()); //precondition
    return adjLists[i].find(j) != adjLists[i].end();
  }
  int n() { // returns the number of vertices in this Graph
    return adjLists.size();
  }
  int m() { // returns the number of edges in this Graph
    int edges = 0;
    for(auto v:adjLists){
      edges+=v.size();
    }
    return edges/2;
  }
 private://Assume vertices are numbered 0, 1, ... , n-1
  std::vector<std::set<int> > adjLists;
};

int main () {
  Graph G = Graph();
  G.addVertex();
  G.addVertex();
  G.addVertex();
  G.addVertex();
  G.addEdge(0,1);
  G.addEdge(1,2);
  G.addEdge(0,3);
  G.addEdge(0,2);
}
