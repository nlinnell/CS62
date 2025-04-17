#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stack>

using namespace std;


class DirectedGraph {
public:
  DirectedGraph(){}
  int n() {
    return outAdjacencyList.size();
  }
  int m() {
    int count = 0;
    for(auto list : outAdjacencyList) {
        count += list.size();
    }
    return count ;
  }
  void addVertex() {
    outAdjacencyList.push_back(set<int>());
  }
  void addEdge(int id1, int id2) {
    outAdjacencyList[id1].insert(id2);
  }
// what does this print?
  void DFSHelper(int current, std::vector<bool> &visited) {
    // HERE
    std::cout << "current: " << current << std::endl;
    std::cout << "visited: ";
    for (int i = 0; i < n(); i ++) {
      std::cout << i << (visited[i] ? "T" : "F") << " ";
    }
    std::cout << std::endl;

    for (auto neighbor : outAdjacencyList[current]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        DFSHelper(neighbor, visited);
      }
    }
  }
  
  void DFS(int source){
    vector<bool> visited(n(), 0);
    visited[source] = true;
    DFSHelper(source, visited);
  }

private:
  vector<set<int> > outAdjacencyList;
};

  
int main() {
    DirectedGraph G;
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addVertex();
    G.addEdge(0,1);
    G.addEdge(2,1);
    G.addEdge(1,3);
    G.addEdge(3,2);
    G.addEdge(4,0);
    G.addEdge(4,1);
    G.addEdge(4,3);
    
    G.DFS(4);
    return 0;
}

