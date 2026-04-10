#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cassert>


class Graph {
public:
  // pre: none
  // post: an empty Graph has been created
  Graph() {}

  // pre: none
  // post: returns the number of vertices in this Graph
  int n() const {
    return adjLists.size();
  }

  // pre: none
  // post: returns the number of edges in this Graph
  int m() const {
    int totalEdges = 0;
    for(auto aList:adjLists){
      totalEdges+=aList.size();
    }
    return totalEdges/2;
  }

  // pre: none
  // post: a new vertex with label n() has been added to this Graph
  void addVertex() {
    adjLists.push_back(std::set<int>());
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} has been added to this Graph
  //       if it is not an edge already
  void addEdge(int i, int j) {
    assert(i<n()&&j<n());
    adjLists[i].insert(j);
    adjLists[j].insert(i);
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} is not in this Graph
  void deleteEdge(int i, int j) {
    assert(i<n()&&j<n());
    adjLists[i].erase(j);
    adjLists[j].erase(i);
  }


  //pre: source < n()
  //post: returns a breadth first search traversal starting at vertex source
  std::vector<int>  breadthFirstSearch(int source) {
    assert(source<n());
    std::queue<int> q;//Items that have been visited but not expanded
    std::vector<bool> visited(n(), false);
    std::vector<int> traversal;
    q.push(source);
    traversal.push_back(source);
    visited[source] = true;
    while(!q.empty()){
      int current = q.front();
      q.pop();
      for(auto neighbor:adjLists[current]){//explore all of current's neighbors
        if(!visited[neighbor]){
          q.push(neighbor);
          traversal.push_back(neighbor);
          visited[neighbor] = true;
        }
      }
    }
    return traversal;
  }

 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  std::vector<std::set<int> > adjLists;
};

using namespace std;
int main () {
  if (1) {
    // in class demo
    Graph g;
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(4,3);
    g.addEdge(0,4);
  
    std::vector<int> bfs = g.breadthFirstSearch(2);
    for(auto v:bfs){
      std::cout<<v<<" ";
    }
    std::cout<<endl;
  } else {
    // in class exercise
    Graph g;
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(4,3);
    g.addEdge(0,4);

    std::vector<int> bfs = g.breadthFirstSearch(4);
    for(auto v:bfs){
      std::cout<<v<<" ";
    }
    std::cout<<endl;
  }
}

