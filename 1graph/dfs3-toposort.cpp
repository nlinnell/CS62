#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stack>
#include <algorithm>

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
  bool topoSortHelper(int current, std::vector<int> &visited, vector<int> & ordering) {
    // HERE
    std::cout << "current: " << current << std::endl;
    std::cout << "visited: ";
    for (int i = 0; i < n(); i ++) {
      std::cout << i << visited[i] << " ";
    }
    std::cout << std::endl;

    for (auto neighbor : outAdjacencyList[current]) {
      if(visited[neighbor]==0){
        visited[neighbor] = 1;
        if(!topoSortHelper(neighbor, visited, ordering)) return false;
      }
      else if(visited[neighbor]==1){//we've found a CYCLE
        return false; 
      }
      //else if(visited[neighbor]==2)//Do nothing
    }
    visited[current] = 2;
    ordering.push_back(current);
    return true;
  }
  
  vector<int> topoSort(int source){
    vector<int> visited(n(), 0);
    vector<int> ordering;
    int next = source;
    while(next!= -1){
      visited[next] = 1;
      if(!topoSortHelper(next, visited, ordering)) return vector<int>();//if there's a cycle return empty path
      next = unexplored(visited);
    }
    return ordering;
  }

  int unexplored(vector<int> visited){
    for(int i=0; i<visited.size(); ++i){
      if(visited[i]==0)
        return i;
    }
    return -1;
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
    //G.addEdge(2,1);//this one adds a cycle
    G.addEdge(1,3);
    G.addEdge(3,2);
    G.addEdge(4,0);
    G.addEdge(4,1);
    G.addEdge(4,3);
    
    vector<int> order = G.topoSort(4);
    cout<<"ordering: ";
    for(int i=0; i<order.size(); ++i)
      cout<<order[i]<<" ";
    return 0;
}

