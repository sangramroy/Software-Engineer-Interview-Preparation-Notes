// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

class graph{
 
  public:
  map<int,set<int>> adj;
  void add(int u,int v,int dir)
  {
      adj[u].insert(v);
      if(!dir)
      adj[v].insert(u);
  }
  
  void print()
  {
      for(auto it:adj)
      {
      cout<<it.first<<"--->";
      for(auto neighbour:it.second)
      {
          cout<<neighbour<<" ";
      }
      cout<<endl;
  }
  }
  
  bool dfsCycleDetect(int node, int parent, unordered_map<int, bool>& visited, map<int, set<int>>& adj) {
    visited[node] = true;

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (dfsCycleDetect(neighbour, node, visited, adj)) {
                return true;
            }
        } else if (neighbour != parent) {
            // If an adjacent is visited and not parent of current vertex, then there's a cycle
            return true;
        }
    }

    return false;
}

void cyclecheckdfs(map<int, set<int>>& adj) {
    unordered_map<int, bool> visited;

    for (auto& pair : adj) {
        int node = pair.first;
        if (!visited[node]) {
            if (dfsCycleDetect(node, -1, visited, adj)) {
                cout << "\ncycle present:";
                return;
            }
        }
    }

    cout << "\ncycle not present:";
}


};

int main() {
     graph g;
     g.add(0,1,0);
     g.add(1,2,0);
     g.add(1,3,0);
     g.add(3,4,0);
     g.add(3,5,0);
     g.add(6,5,0);
     g.cyclecheckdfs();
    return 0;
}


