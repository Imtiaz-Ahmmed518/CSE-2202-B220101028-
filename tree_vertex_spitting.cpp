#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<vector<int>> components;

void dfs(int node, vector<int> &comp) {
    visited[node] = true;
    comp.push_back(node);

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next, comp);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    graph.resize(n + 1);
    visited.assign(n + 1, false);

    cout << "Enter " << n - 1 << " edges:\n";
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int splitVertex;
    cout << "Enter the vertex to split/remove: ";
    cin >> splitVertex;

    visited[splitVertex] = true;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> comp;
            dfs(i, comp);
            components.push_back(comp);
        }
    }

    cout << "\nComponents after splitting the tree at vertex "
         << splitVertex << ":\n";

    for (int i = 0; i < components.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int v : components[i]) cout << v << " ";
        cout << endl;
    }

    return 0;
}
