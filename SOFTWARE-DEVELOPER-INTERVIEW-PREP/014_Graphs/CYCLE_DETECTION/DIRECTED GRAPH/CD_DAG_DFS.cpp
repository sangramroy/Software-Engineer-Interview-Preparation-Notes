#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

class Graph {
public:
    unordered_map<int, set<int>> adj;

    void addEdge(int u, int v) {
        adj[u].insert(v); // directed edge u -> v
    }

    bool dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited) {
        visited[node] = true;
        dfsVisited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, visited, dfsVisited)) {
                    return true;
                }
            } else if (dfsVisited[neighbor]) {
                // Cycle found
                return true;
            }
        }

        dfsVisited[node] = false; // backtrack
        return false;
    }

    bool hasCycle() {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;

        for (auto& it : adj) {
            int node = it.first;
            if (!visited[node]) {
                if (dfs(node, visited, dfsVisited)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1); // Creates a cycle: 1 -> 2 -> 3 -> 1

    if (g.hasCycle()) {
        cout << "Cycle detected in the directed graph." << endl;
    } else {
        cout << "No cycle found in the directed graph." << endl;
    }

    return 0;
}
