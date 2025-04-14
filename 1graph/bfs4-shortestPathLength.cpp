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
    return adjLists_.size();
  }

  // pre: none
  // post: returns the number of edges in this Graph
  int m() const {
    int count = 0;
    for(auto list : adjLists_) {
        count += list.size();
    }
    return count / 2;
  }

  // pre: none
  // post: a new vertex with label n() has been added to this Graph
  void addVertex() {
    adjLists_.push_back(std::set<int>{});
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} has been added to this Graph
  //       if it is not an edge already
  void addEdge(int i, int j) {
    adjLists_[i].insert(j);
    adjLists_[j].insert(i);
  }

  // pre: i < n() && j < n()
  // post: edge {i, j} is not in this Graph
  void deleteEdge(int i, int j) {
    adjLists_[i].erase(j); 
    adjLists_[j].erase(i); 
  }

  int shortestPathLength(int from, int to) {
    std::queue<int> q;
    std::vector<bool> visited (n(), 0);
    //What info do I need to track for each vertex?
    std::vector<int> distance(n(), -1);

    visited[from] = true;
    q.push(from);
    distance[from] = 0;

    while (q.size() > 0) {
      int current = q.front();
      q.pop();
      for (auto neighbor : adjLists_[current]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
          distance[neighbor] = distance[current]+1;
        }
      }
      cout << "current: " << current << endl;
    }
    return distance[to];

  }

 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  std::vector<std::set<int> > adjLists_;
};


int main () {
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

  std::cout << G.shortestPathLength(0,2) << std::endl;
}
