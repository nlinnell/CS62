#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cassert>

class Graph {
public:
  // pre: none
  // post: an empty Graph has been created
  Graph() {}

  // pre: none
  // post: returns the number of vertices in this Graph
  int n() const {
    return adjacencyLists.size();
  }

  // pre: none
  // post: returns the number of edges in this Graph
  int m() const {
    int count = 0;
    for(auto list : adjacencyLists) {
        count += list.size();
    }
    return count / 2;
  }

  // pre: none
  // post: a new vertex with label n() has been added to this Graph
  void addVertex() {
    adjacencyLists.push_back(std::set<int>{});
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} has been added to this Graph
  //       if it is not an edge already
  void addEdge(int i, int j) {
    adjacencyLists[i].insert(j);
    adjacencyLists[j].insert(i);
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} is not in this Graph
  void deleteEdge(int i, int j) {
    adjacencyLists[i].erase(j); 
    adjacencyLists[j].erase(i); 
  }

  //pre: from < n(), to < n()
  //post: returns the shortest path starting at vertex from 
  //and ending at vertex to
  std::vector<int> shortestPath(int from, int to) {
    //Start with BFS
    //What additional information to track?
    //What to change?
    assert(from<n() && to<n());
    //std::vector<int> traversal;//Don't need the traversal anymore
    std::queue<int> q;//vertices that have been visited but not processed 
    std::vector<bool> visited(n(), false);
    std::vector<int> previous(n(), -1);
    //traversal.push_back(from);
    q.push(from);
    visited[from] = true;
    while(! q.empty()){
      int current = q.front();
      q.pop();
      for(auto neighbor : adjacencyLists[current]){
        if(! visited[neighbor]){
          //traversal.push_back(neighbor);
          q.push(neighbor);
          previous[neighbor] = current;
          visited[neighbor] = true;
        }
      }    //HERE (for paper activity)
    }
    int current = to;
    std::vector<int> path;
    while(current != -1){
      path.push_back(current);
      current = previous[current];
    }
    std::reverse(path.rbegin(), path.rend());
    return path;
  }

 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  std::vector<std::set<int> > adjacencyLists;
};

int main () {
  if (0) {
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

    std::vector<int> path = g.shortestPath(0,3);
    std::cout << "Number of Vertices on Path: " << path.size() << std::endl << "Path: ";
    for (auto v : path) {
      std::cout << v << " ";
    }
    std::cout << std::endl;
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

    std::vector<int> path = g.shortestPath(0,2);
    std::cout << "Number of Vertices on Path: " << path.size() << std::endl << "Path: ";
    for (auto v : path) {
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }
}

