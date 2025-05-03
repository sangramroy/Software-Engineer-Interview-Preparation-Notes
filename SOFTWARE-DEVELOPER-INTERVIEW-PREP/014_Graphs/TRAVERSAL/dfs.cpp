#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph {
    unordered_map<int, vector<pair<int, int>>> adj;

public:
    void addEdge(int u, int v, bool dir, int w) {
        adj[u].push_back({v, w});
        if (!dir)
            adj[v].push_back({u, w});
    }

    void print() {
        for (auto it : adj) {
            cout << it.first << " --> ";
            for (auto k : it.second) {
                cout << k.first << " (" << k.second << ") ";
            }
            cout << endl;
        }
    }
    
    void dfsHelper(int node, unordered_map<int, bool> &visited) {
        cout << node << " ";
        visited[node] = true;

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor.first]) {
                dfsHelper(neighbor.first, visited);
            }
        }
    }

    void dfsAll() {
        unordered_map<int, bool> visited;
        cout << "DFS Traversal (All Components): ";
        for (auto it : adj) {
            if (!visited[it.first]) {
                dfsHelper(it.first, visited);
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 0, 10);
    g.addEdge(1, 2, 0, 50);
    g.addEdge(1, 3, 0, 40);
    g.addEdge(3, 5, 0, 20);
    g.addEdge(3, 7, 0, 30);
    g.addEdge(7, 6, 0, 40);
    g.addEdge(7, 4, 0, 10);
    
    // Add an isolated component
    g.addEdge(10, 11, 0, 100);

    g.print();
    g.dfsAll();

    return 0;
}
