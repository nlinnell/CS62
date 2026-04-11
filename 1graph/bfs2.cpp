#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void print_queue(queue<int> q){
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
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
    adjLists.push_back(set<int> ());
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

  // what is wrong with this BFS?
  void breadthFirstSearch(int source) {
    queue<int> q;
    q.push(source);
    while (q.size() > 0) {
      int current = q.front();
      q.pop();
      cout << "=====\ncurrent: " << current << endl;
      cout << "q: ";
      print_queue(q);
      for (auto neighbor : adjLists[current]) {
          q.push(neighbor);
      }
      cout << "q: ";
      print_queue(q);
    }
  }
 private:
  // assumption: vertices are numbered 0, 1, ..., n-1
  vector<set<int> > adjLists;
};


int main () {
  Graph g;
  g.addVertex();
  g.addVertex();
  g.addVertex();
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.breadthFirstSearch(0);

}
