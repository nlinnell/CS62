#include <iostream>
#include <vector>
#include <set>
#include <queue>

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
  //pre: from < n(), to < n()
  //post: returns the length of the shortest path starting at vertex from 
  //and ending at vertex to
  int shortestPathLength(int from, int to) {
    queue<int> q;
    vector<bool> visited (n(), 0);
    vector<int> distance(n(), -1);
    distance[from] = 0;//FILL IN
    visited[from] = true;
    q.push(from);
    while (q.size() > 0) {
      int current = q.front();
      q.pop();
      for (auto neighbor : adjLists[current]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          distance[neighbor] = distance[current]+1;//FILL IN
          q.push(neighbor);
        }
      }
    }
    return distance[to];//FILL IN
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

  std::cout << g.shortestPathLength(0,2) << std::endl;
}
