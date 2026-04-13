#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cassert>

using namespace std;

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

  bool isAcyclic(int source) {
    assert(source<n());
    std::queue<int> q;//Items that have been visited but not expanded
    std::vector<bool> visited(n(), false);
    q.push(source);
    visited[source] = true;
    while(!q.empty()){
      int current = q.front();
      q.pop();
      int count = 0;
      for(auto neighbor:adjLists[current]){//explore all of current's neighbors
        if(!visited[neighbor]){
          q.push(neighbor);
          visited[neighbor] = true;
        }
        else{
          count++;
          if(count>=2){
            return false;
          }
        }
      }
    }
    return true;
  }

 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  std::vector<std::set<int> > adjLists;
};


int main () {
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

  std::cout << g.isAcyclic(5) << std::endl;
}
