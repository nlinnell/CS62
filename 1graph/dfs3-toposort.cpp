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
    return outAdjacencyLists.size();
  }
  int m() {
    int count = 0;
    for(auto list : outAdjacencyLists) {
        count += list.size();
    }
    return count ;
  }
  void addVertex() {
    outAdjacencyLists.push_back(set<int>());
  }
  void addEdge(int id1, int id2) {
    outAdjacencyLists[id1].insert(id2);
  }


  
  vector<int> topoSort(int source){
    std::vector<int> visited(n(), 0);
    std::vector<int> traversal;
    visited[source] = 1;
    if(topoSortHelper(source, visited, traversal))
      return traversal;
    else 
      return vector<int>();
  }



private:
  bool topoSortHelper(int current, std::vector<int> &visited, 
    vector<int> & traversal) {
   
    for(auto neighbor:outAdjacencyLists[current]){
      if(visited[neighbor]==1)//the neighbor is on the path to current, so there's a cycle
        return false;
      else if(visited[neighbor]==0){
        visited[neighbor] = 1;

        if(!topoSortHelper(neighbor, visited, traversal))
          return false;
      }//if visited[neighbor]==2 do nothing
    }
    traversal.push_back(current);
    visited[current] = 2;
    return true;
  }
  int unexplored(vector<int> visited){
    for(int i=0; i<visited.size(); ++i){
      if(visited[i]==0)
        return i;
    }
    return -1;
  }

  vector<set<int> > outAdjacencyLists;
    
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
