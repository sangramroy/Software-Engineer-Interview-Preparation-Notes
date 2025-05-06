#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
public:
    map<int, set<int>> adj;

    void addEdge(int u, int v) {
        adj[u].insert(v);  // Directed edge u → v
    }

    void printGraph() {
        cout << "Graph Adjacency List:\n";
        for (auto it : adj) {
            cout << it.first << " -> ";
            for (int neighbor : it.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void topologicalSortBFS() {
        unordered_map<int, int> indegree;

        // Step 1: Initialize indegree for all nodes
        for (auto it : adj) {
            int u = it.first;
            for (int v : it.second) {
                indegree[v]++;
            }
            // Ensure the node with no outgoing edges is also in indegree map
            if (!indegree.count(u)) {
                indegree[u] = 0;
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
        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Check for cycle
        if (topoOrder.size() != indegree.size()) {
            cout << "Cycle detected. Topological sort not possible.\n";
            return;
        }

        cout << "Topological Sort (BFS-based): ";
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();
    g.topologicalSortBFS();

    return 0;
}
