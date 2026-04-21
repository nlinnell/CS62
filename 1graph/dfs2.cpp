#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>


class Graph {
public:
  Graph() {}
  int n() const {
    return adjLists.size();
  }
  int m() const {
    int count = 0;
    for(auto list : adjLists) {
        count += list.size();
    }
    return count / 2;
  }
  void addVertex() {
    adjLists.push_back(std::set<int>{});
  }
  void addEdge(int i, int j) {
    adjLists[i].insert(j);
    adjLists[j].insert(i);
  }

  std::vector<int> depthFirstSearch(int source) {
    std::vector<bool> visited(n(), false);
    std::vector<int> traversal;
    DFSHelper(source, visited, traversal);
    return traversal;
  }
 private://What is the meaning of the values in current's call stack?
  void DFSHelper(int current, std::vector<bool> &visited, 
                              std::vector<int> &traversal) {
    // Printing out the current state
    std::cout << "current: " << current << std::endl;
    std::cout << "visited: ";
    for (int i = 0; i < n(); i ++) {
      std::cout << i << (visited[i] ? "T" : "F") << " ";
    }
    std::cout << std::endl;
    
    visited[current] = true;
    traversal.push_back(current);
    for(auto neighbor:adjLists[current]){
      if(!visited[neighbor]){
        DFSHelper(neighbor, visited, traversal);
      }
    }

    // Printing out the current state
    std::cout << "current: " << current << std::endl;
    std::cout << "visited: ";
    for (int i = 0; i < n(); i ++) {
      std::cout << i << (visited[i] ? "T" : "F") << " ";
    }
    std::cout << std::endl;
  }
  // assumption: vertices are numbered 0, 1, ..., n-1
  std::vector<std::set<int> > adjLists;
};


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

    g.depthFirstSearch(0);
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

    g.depthFirstSearch(4);
  }
}

/*
    // HERE
    std::cout << "current: " << current << std::endl;
    std::cout << "visited: ";
    for (int i = 0; i < n(); i ++) {
      std::cout << i << (visited[i] ? "T" : "F") << " ";
    }
    std::cout << std::endl;
    */