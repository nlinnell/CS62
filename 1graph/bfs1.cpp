#include <iostream>
#include <vector>
#include <set>
#include <queue>





class Graph {
public:
  // pre: none
  // post: an empty Graph has been created
  Graph() {}

  // pre: none
  // post: returns the number of vertices in this Graph
  int n() const {

  }

  // pre: none
  // post: returns the number of edges in this Graph
  int m() const {

  }

  // pre: none
  // post: a new vertex with label n() has been added to this Graph
  void addVertex() {

  }

  // pre: i < n() && j < n()
  // post: edge {i, j} has been added to this Graph
  //       if it is not an edge already
  void addEdge(int i, int j) {

  }

  // pre: i < n() && j < n()
  // post: edge {i, j} is not in this Graph
  void deleteEdge(int i, int j) {

  }


  // what does this print out?
  void BFS(int source) {



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

   // G.BFS(2);
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

/*
void print_queue(std::queue<int> q)
{
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}
*/