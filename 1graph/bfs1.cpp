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
    return adjLists_.size();
  }

  // pre: none
  // post: returns the number of edges in this Graph
  int m() const {
    int totalEdges = 0;
    for(auto alist:adjLists_){
      totalEdges+=alist.size();
    }
    return totalEdges/2;
  }

  // pre: none
  // post: a new vertex with label n() has been added to this Graph
  void addVertex() {
    adjLists_.push_back(std::set<int>());
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} has been added to this Graph
  //       if it is not an edge already
  void addEdge(int i, int j) {
    assert(i<n()&&j<n());
    adjLists_[i].insert(j);
    adjLists_[j].insert(i);
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} is not in this Graph
  void deleteEdge(int i, int j) {
    assert(i<n()&&j<n());
    adjLists_[i].erase(j);
    adjLists_[j].erase(i);
  }


 
  void BFS(int source) {
    std::queue<int> q;
    std::vector<bool> visited(n(), false);
    //std::vector<int> ordering;//If we wanted to return the traversal instead of printing it
    q.push(source);
    visited[source] = true;
    while(!q.empty()){
      int vertex = q.front();
      q.pop();
      std::cout<<vertex<<", ";
      //ordering.push_back(vertex);
      for(auto neighbor:adjLists_[vertex]){
        if(!visited[neighbor]){
          q.push(neighbor);
          visited[neighbor] = true;
        }
      }
      //return ordering;
    }

  }

 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  std::vector<std::set<int> > adjLists_;
};

using namespace std;
int main () {
  if (1) {
    // in class demo
    Graph G;
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(1,3);
    G.addEdge(1,4);
    G.addEdge(4,3);
    G.addEdge(0,4);

    G.BFS(2);
  } else {
    // in class exercise
    Graph G;
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(2,5);
    G.addEdge(3,5);
    G.addEdge(4,3);
    G.addEdge(0,4);

    G.BFS(4);
  }
}

