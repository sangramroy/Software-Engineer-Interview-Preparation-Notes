#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <stack>
#include <set>
using namespace std;

class Graph {
public:
    map<int, set<int>> adj;

    void addEdge(int u, int v) {
        adj[u].insert(v); // Directed edge u -> v
    }

    void topoDFS(int node, unordered_map<int, bool>& visited, stack<int>& st) {
        visited[node] = true;

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                topoDFS(neighbour, visited, st);
            }
        }

        // Push after visiting all neighbors
        st.push(node);
    }

    void topologicalSortDFS() {
        unordered_map<int, bool> visited;
        stack<int> st;

        for (auto& pair : adj) {
            if (!visited[pair.first]) {
                topoDFS(pair.first, visited, st);
            }
        }

        cout << "Topological Sort (DFS-based): ";
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }

    void printGraph() {
        cout << "Graph Adjacency List:\n";
        for (auto& [u, neighbours] : adj) {
            cout << u << " -> ";
            for (auto v : neighbours) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    // Sample DAG
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);

    g.printGraph();
    g.topologicalSortDFS();

    return 0;
}
