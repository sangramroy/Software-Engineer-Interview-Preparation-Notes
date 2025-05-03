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

    void bfsAll() {
        unordered_map<int, bool> visited;
        cout << "BFS Traversal (All Components): ";

        for (auto it : adj) {
            int start = it.first;
            if (!visited[start]) {
                queue<int> q;
                q.push(start);
                visited[start] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    cout << node << " ";

                    for (auto neighbor : adj[node]) {
                        if (!visited[neighbor.first]) {
                            q.push(neighbor.first);
                            visited[neighbor.first] = true;
                        }
                    }
                }
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
    g.bfsAll();
    return 0;
}
