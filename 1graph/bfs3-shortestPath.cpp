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
    return adjLists.size();
  }

  // pre: none
  // post: returns the number of edges in this Graph
  int m() const {
    int count = 0;
    for(auto list : adjLists) {
        count += list.size();
    }
    return count / 2;
  }

  // pre: none
  // post: a new vertex with label n() has been added to this Graph
  void addVertex() {
    adjLists.push_back(std::set<int>{});
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} has been added to this Graph
  //       if it is not an edge already
  void addEdge(int i, int j) {
    adjLists[i].insert(j);
    adjLists[j].insert(i);
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} is not in this Graph
  void deleteEdge(int i, int j) {
    adjLists[i].erase(j); 
    adjLists[j].erase(i); 
  }

  //pre: from < n(), to < n()
  //post: returns the shortest path starting at vertex from 
  //and ending at vertex to
  std::vector<int> shortestPath(int from, int to) {
    //Start with BFS
    //What additional information to track?
    //What to change?
   assert(from<n());
    std::queue<int> q;//Items that have been visited but not expanded
    std::vector<bool> visited(n(), false);
    std::vector<int> previous(n(), -1);
    //Where should previous get updated?
    q.push(from);
    visited[from] = true;
    while(!q.empty()){
      int current = q.front();
      q.pop();
      for(auto neighbor:adjLists[current]){//explore all of current's neighbors
        if(!visited[neighbor]){
          q.push(neighbor);
          visited[neighbor] = true;
          previous[neighbor] = current;
        }
      }
    }
    std::vector<int> path;
    int current = to;
    while(current!=-1){//Get the path (it'll be backwards at first)
      path.push_back(current);
      current = previous[current];
    }
    std::reverse(path.rbegin(), path.rend());
    return path;
  }

 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  std::vector<std::set<int> > adjLists;
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

