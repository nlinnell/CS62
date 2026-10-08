#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>


class Graph {
public:
  Graph() {}
  int n() const {
    return adjacencyLists.size();
  }
  int m() const {
    int count = 0;
    for(auto list : adjacencyLists) {
        count += list.size();
    }
    return count / 2;
  }
  void addVertex() {
    adjacencyLists.push_back(std::set<int>{});
  }
  void addEdge(int i, int j) {
    adjacencyLists[i].insert(j);
    adjacencyLists[j].insert(i);
  }

  std::vector<int> depthFirstSearch(int source) {
    std::vector<bool> visited(n(), false);
    std::vector<int> traversal;
    visited[source] = true;
    traversal.push_back(source);
    DFSHelper(source, visited, traversal);
    return traversal;
  }
 private://What is the meaning of the values in current's call stack?
  void DFSHelper(int current, std::vector<bool> &visited, 
                              std::vector<int> &traversal) {
      for(auto neighbor : adjacencyLists[current]){
        if(! visited[neighbor]){
          traversal.push_back(neighbor);
          visited[neighbor] = true;
          DFSHelper(neighbor, visited, traversal);
        }
      } //HERE     

/*
    // Printing out the current state
    std::cout << "current: " << current << std::endl;
    std::cout << "visited: ";
    for (int i = 0; i < n(); i ++) {
      std::cout << i << (visited[i] ? "T" : "F") << " ";
    }
    std::cout << std::endl;*/
  }
  // assumption: vertices are numbered 0, 1, ..., n-1
  std::vector<std::set<int> > adjacencyLists;
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

    for(auto v: g.depthFirstSearch(0))
      std::cout<<v<<std::endl;
  } else {
    // class exercise
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

    for(auto v: g.depthFirstSearch(4))
      std::cout<<v<<std::endl;
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