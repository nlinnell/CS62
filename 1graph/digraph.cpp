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
  std::vector<int> depthFirstSearch(int source){
    vector<bool> visited(n(), 0);
    visited[source] = true;
    vector<int> traversal;
    traversal.push_back(source);
    DFSHelper(source, visited, traversal);
    return traversal;
  }
private:
  vector<set<int> > outAdjacencyList;

  void DFSHelper(int current, std::vector<bool> &visited,
                  std::vector<int>& traversal) {
    for(auto neighbor: outAdjacencyList[current]){
      if(!visited[neighbor]){
        visited[neighbor] = true;
        traversal.push_back(neighbor);
        DFSHelper(neighbor, visited, traversal);
      }
    }
  }
};

  
int main() {
    DirectedGraph g;
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(4,3);
    
    g.depthFirstSearch(4);
    return 0;
}

