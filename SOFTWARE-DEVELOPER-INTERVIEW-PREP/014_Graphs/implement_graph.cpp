// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class graph{
  unordered_map<int,vector<pair<int,int>>> adj;
  public:
  void addedge(int u,int v,bool dir,int w)
  {
      adj[u].push_back({v,w});
      if(!dir)
       adj[v].push_back({u,w});
  }
  
  void print()
  {
      for(auto it:adj)
      {
          cout<<it.first<<"-->";
          for(auto k:it.second)
          {
              cout<<k.first<<" ("<<k.second<<") "<<" ";
          }
          cout<<endl;
      }
  }
};

int main() {
    graph g;
    g.addedge(0,1,0,10);
    g.addedge(1,2,0,50);
    g.addedge(1,3,0,40);
    g.addedge(3,5,0,20);
    g.addedge(3,7,0,30);
    g.addedge(7,6,0,40);
    g.addedge(7,4,0,10);
    g.print();
    return 0;
}