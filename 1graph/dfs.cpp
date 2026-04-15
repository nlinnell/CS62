#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <cassert>

using namespace std;

void print_stack(stack<int> s)
{
  stack<int> s2;
  while (!s.empty()) {
    s2.push(s.top());
    s.pop();
  }
  while (!s2.empty())
  {
    cout << s2.top() << " ";
    s2.pop();
  }
  cout << endl;
}

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
    adjLists.push_back(set<int>{});
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

  std::vector<int> depthFirstSearch(int source) {
    assert(source<n());
    std::stack<int> stk;//Items that have been visited but not expanded
    std::vector<bool> visited(n(), false);
    std::vector<int> traversal;
    stk.push(source);
    while(!stk.empty()){
      int current = stk.top();
      stk.pop();
      if(!visited[current]){
        traversal.push_back(current);//Should I do this here
        visited[current] = true;
        for(auto neighbor:adjLists[current]){//explore all of current's neighbors
          if(!visited[neighbor]){
            stk.push(neighbor);
          }
        }

       // HERE
        // print statements added
        cout << "current: " << current << endl;
        cout << "stk: ";
        print_stack(stk);
        cout << "visited: ";
        for (int i = 0; i < n(); i ++) {
          cout << i << (visited[i] ? "T" : "F") << " ";
        }
        cout << endl;
        // HERE

      }
    }
    return traversal;
  }

 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  vector<set<int> > adjLists;
};

// in class demo
/*
int main () {
  Graph G;
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

  g.DFS(0);
}
*/

// in class exercise
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

  g.depthFirstSearch(4);
}
/*
       // HERE
        // print statements added
        cout << "current: " << current << endl;
        cout << "stck: ";
        print_stack(stck);
        cout << "visited: ";
        for (int i = 0; i < n(); i ++) {
          cout << i << (visited[i] ? "T" : "F") << " ";
        }
        cout << endl;
        // HERE
        */