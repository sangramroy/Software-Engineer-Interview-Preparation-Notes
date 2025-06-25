/*
IMPLEMENT GRAPH USING ADJACENCY LIST
1.TRAVERSAL -BFS
2.TRAVERSAL -DFS

LOGIC FOR BELOW: -(NODE IS VISITED && NEIGHBOUR!=PARENT[NODE])
3.CYCLE DETECTION - UNDIRECTED-BFS - VISITED MAP AND PARENT VISITED MAP 
4.CYCLE DETECTION - UNDIRECTED-DFS - VISITED MAP AND PARENT VISITED MAP

LOGIC FOR BELOW: -(NODE VISITED[NODE] &&  DFSVISITED[NODE])
5.CYCLE DETECTION - DIRECTED-DFS - VISITED MAP AND DFS VISITED MAP (PARENT FAILS HERE)

6.TOPOLOGICAL SORT - BFS-(KAHNS ALGO) (INDEGREE CREATE KRKE CHALNA HAI OR 0 INDEGREE WAALE KO QUEUE MAIN DAALNA HI AND SIMPLE BFS)

LOGIC CNT=NO OF VERTICES :- CYCLE NOT PRESENT : - CNT=INDEGREE VALUES
7.CYCLE DETECTION - DIRECTED-BFS - KAHNS ALGO + 2 LINE CHANGES

8.TOPOLOGICAL SORT - DFS USING STACK WHILE RETURNING AND STORING IN VECTOR WHILE RETURNING

IMPLEMENTING BELOW GRAPH FOR BFS,DFS TRAVERSAL(Q1,Q2)  + WILL CREATE EDGE FROM 5 TO 6 FOR CYCLE DETECTION UNDIRECTED GRAPH (Q3,Q4)

     (10)        (50)
  0-------1------------2
           \
          (40)
            \
             3
           /   \
        (20)   (30)
         /       \
        5          7
        \         / \
        (15)   (40)  (10)
            \  /     \
              6       4
              
              
 disconnected component also
              
      (30)   (25)
  9-------8---------10
  
  //use map for sorted and as 0 as rrot node 
  //if unordered_map for adjlist root can be any node

*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;

class graphforfirstfourQ{
  public:
  //unordered_map<int,vector<pair<int,int>>> adjlist; //for unsorted one
  map<int,vector<pair<int,int>>> adjlist; // for sorted one
  void addedge(int u,int v,int dir, int wt)
  {
      adjlist[u].push_back({v,wt});
      if(!dir) adjlist[v].push_back({u,wt});
  }
  
  void printadjlist()
  {   cout<<"\nPrinting adjaceny list: \n";
      for(auto it:adjlist)
      {
          cout<<it.first<<"---->";
          for(auto neighbour:it.second)
          {
              cout<<neighbour.first<<"("<<neighbour.second<<")"<<"   ";
          }
          cout<<endl;
      }
  }
///////////////////////////////////////////////////////////////////////////////////////////////  
  void bfsall()
{
    cout<<"\nBFS trversal: \n";
    unordered_map<int,int> visited;
    queue<int> q;
    for(auto it:adjlist) 
    {
        if(!visited[it.first])
        {
        visited[it.first]=1;
        q.push(it.first);
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            cout<<front<<" ";
            for(auto n:adjlist[front])
            {
                int first=n.first;
                if(!visited[first])
                {
                    visited[first]=1;
                    q.push(first);
                }
        }
       }
    }
    }
 }
 ///////////////////////////////////////////////////////////////////////////////////////////////
 void dfshelper(int data,unordered_map<int,int> &visited)
 {
        cout<<data<<" ";
        visited[data]=1;
        for(auto n:adjlist[data])
        {
            if(!visited[n.first])
            {
                dfshelper(n.first,visited);
            }
        }
}

 void dfsall()
 {
    cout<<"\nDFS trversal: \n";
    unordered_map<int,int> visited;
       for(auto it:adjlist) 
     {
           if(!visited[it.first])
           dfshelper(it.first,visited); 
     }
 }

///////////////////////////////////////////////////////////////////////////////////////////////////
  void cycledetectionbfsall()
{
    cout<<"\nBFS trversal for cycle detection: \n";
    unordered_map<int,int> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    for(auto it:adjlist) 
    {
        if(!visited[it.first])
        {
        visited[it.first]=1;
        parent[it.first]=-1;
        q.push(it.first);
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            cout<<front<<" ";
            for(auto n:adjlist[front])
            {
                int first=n.first;
                if(!visited[first])
                {
                    visited[first]=1;
                    parent[first]=front;
                    q.push(first);
                }
                else
                {
                    if(first!=parent[front])
                    {
                        cout<<"\n cycle present:"<<endl;
                        return;
                    }
                }
        }
       }
    }
    }
       cout<<"\ncycle not present:"<<endl;
 }
 
/////////////////////////////////////////////////////////////////////////////////////////////////////
 bool dfshelpercycledetection(int node,unordered_map<int,int> &visited,unordered_map<int,int> &parent)
 {
        //cout<<data<<" ";
        visited[node]=1;
        for(auto n:adjlist[node])
        {
            int neighbour=n.first;
            if(!visited[neighbour])
            {
                parent[neighbour]=node;
               if(dfshelpercycledetection(neighbour,visited,parent))
               {
                  //cout<<"\n cycle present:"<<endl;
                  return 1; 
               }
            }
            else
            {
                if(neighbour!=parent[node])
                {
                  //cout<<"\n cycle present:"<<endl;
                    return 1; 
                }
            }
        }
        //cout<<"\n cycle not present:"<<endl;
        return 0;
}

 void dfsallcycledetection()
 {
    cout<<"\nDFS trversal for cycle detection: \n";
    unordered_map<int,int> visited;
    unordered_map<int,int> parent;
       for(auto it:adjlist) 
     {
           int node=it.first;
           if(!visited[node])
           {
                parent[node]=-1;
               if(dfshelpercycledetection(node,visited,parent))
               {
                    cout<<"\n cycle present:"<<endl;
                    return;
               }
           }
     }
     cout<<"\ncycle not present:"<<endl;
 }
 /////////////////////////////////////////////////////////////////////////////////
 // only for acyclic directed graph
 // first calculate indegree
 //push element in q whose indegree==0
 // do bfs pop from queue and while traversing neighbour decrement idegreee of that node that has been popped then insert in q whose indegree==0
 //
 
     void topologicalSortBFS() {
         
      unordered_map<int, int> indegree;
        // Step 1: Calculate indegree and register all nodes
        for (auto it : adjlist) {
            for (auto v : it.second) {
                int val=v.first;
                indegree[val]++;
            }
               if (!indegree.count(it.first)) {
                indegree[it.first] = 0;
            }
        }

        // Step 2: Queue all nodes with 0 indegree
        queue<int> q;
        for (auto it : indegree) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }

        // Step 3: Process the queue
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto neighbor : adjlist[node]) {
                int val=neighbor.first;
                indegree[val]--;
                if (indegree[val] == 0) {
                    q.push(val);
                }
            }
        }

        // Step 4: Check for cycle
        if (ans.size() != indegree.size()) {
            cout << "Cycle detected. Topological sort not possible.\n";
            return;
        }

        cout << "\nTopological Sort (BFS-based): \n";
        for (int node : ans) {
            cout << node << " ";
        }
        cout << endl;
    }
    
 ///////////////////////////////////////////////////////////////////////////////////////
 
 void topologicalsortdfshelper(int node, unordered_map<int,int> &visited,stack<int> &st){
     visited[node]=1;
        for(auto it:adjlist[node])
     {
         if(!visited[it.first])
         {
             topologicalsortdfshelper(it.first,visited,st);
         }
     }
    st.push(node);
 }
 
 void topologicalsortdfs()
 {
    cout<<"\nTopological Sort (DFS-based): \n";
    unordered_map<int,int> visited;
    stack<int> st;
    vector<int> ans;
     for(auto it:adjlist)
     {
         if(!visited[it.first])
         {
             topologicalsortdfshelper(it.first,visited,st);
         }
     }
     while(!st.empty())
     {
         ans.push_back(st.top());
         st.pop();
     }
     for(auto it:ans)
     {
         cout<<it<<" ";
     }
 }

};



int main() 
{
  graphforfirstfourQ obj;
  
  /*
  obj.addedge(0,1,0,10);
  obj.addedge(1,2,0,50);
  obj.addedge(1,3,0,40);
  obj.addedge(3,5,0,20);
  obj.addedge(3,7,0,30);
  obj.addedge(7,6,0,40);
  obj.addedge(7,4,0,10);
  obj.addedge(6,5,0,15);
  obj.addedge(8,9,0,30);
  obj.addedge(8,10,0,25);
  obj.printadjlist();
  obj.bfsall();
  obj.dfsall();
  obj.cycledetectionbfsall();
  obj.dfsallcycledetection();
/*

// for topoligical sort adding direction
      (10)        (50)
  0------->1<-----------2
          \
          (40)
            \
            ->
             3
           /   \
        (20)   (30)
        /       \
       <-       ->
       5           7
        \         /  \
        (15)   (40)    (10)
            \  /        \
            <--          ->
          6                4
              
              
 disconnected component also
              
      (30)   (25)
  9------->8--------->10
  */
  
  //no cycle
  

  obj.addedge(0,1,1,10);
  obj.addedge(2,1,1,50);
  obj.addedge(1,3,1,40);
  obj.addedge(3,5,1,20);
  obj.addedge(3,7,1,30);
  obj.addedge(7,4,1,10);
  obj.addedge(7,6,1,40);
  obj.addedge(5,6,1,15);
  obj.addedge(9,8,1,30);
  obj.addedge(8,10,1,25);
  

  ///////////////////////////////
  //making cycle
  /*
  obj.addedge(0,1,1,10);
  obj.addedge(2,1,1,50);
  obj.addedge(1,3,1,40);
  obj.addedge(3,5,1,20);
  obj.addedge(7,3,1,30);
  obj.addedge(7,4,1,10);
  obj.addedge(6,7,1,40);
  obj.addedge(5,6,1,15);
  obj.addedge(9,8,1,30);
  obj.addedge(8,10,1,25);
  */
  
  /////////////////////////////
  obj.printadjlist();
  obj.bfsall();
  obj.dfsall();
 // obj.cycledetectionbfsall();
  //obj.dfsallcycledetection();
   obj.topologicalSortBFS();
   obj.topologicalsortdfs();
  
  return 0;
}
