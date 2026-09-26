#include <vector>
#include <set>
#include <cassert>


class Graph {
public:
  // create an empty graph
  Graph() {//Can call the default constructor but not necessary
    //adjacencyLists = std::vector<std::set<int> >();
  }

  void addVertex() {  // add a new vertex
    adjacencyLists.push_back(std::set<int>());
  }
  void addEdge(int i, int j) {  // add an edge between ith and jth vertex

  }
  bool areAdjacent(int i, int j) {

  }
  int n() { // returns the number of vertices in this Graph

  }
  int m() { // returns the number of edges in this Graph

  }
 private://Assume vertices are numbered 0, 1, ... , n-1
  std::vector<std::set<int> > adjacencyLists;
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
