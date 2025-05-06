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
  
  void cyclecheckbfs()
{
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    
    for(auto it:adj)
    {
        int start=it.first;
        if(!visited[start])
        {
            visited[start]=1;
            parent[start]=-1;
            q.push(start);
        
          while(!q.empty()){
           int node=q.front(); 
           q.pop();
           for(auto it:adj[node]){
               if(!visited[it])
               {
                   visited[it]=1;
                   q.push(it);
                   parent[it]=node;
               }
               else
               {
                   if(it!=parent[node])
                   {
                       cout<<"\n cycle present:";
                       return;
                   }
               }
           }
        }
        }
    }
    cout<<"\n cycle not present:";
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
     g.cyclecheckbfs();
    return 0;
}