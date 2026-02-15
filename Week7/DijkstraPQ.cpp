#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int s) {
    int n = adj.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int d = top.first;
        int u = top.second;
        if (d > dist[u]) {
            continue;
        }
        for (auto &p: adj[u]) {
            int v = p.first;
            int w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

int main() {
    int V, E, src;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<pair<int,int>>> adj(V);
    cout << "Enter edges in format u/v/w (edge from vertice u to v with weight w): " << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cout << "Enter source node (0 to " << V - 1 << "): ";
    cin >> src;
    if(src < 0 || src >= V) {
        cout << "Invalid source node!" << endl;
        return 0;
    }
    vector<int> result = dijkstra(adj, src);
    cout << "\nShortest distances from node " << src << endl;
    for (int i = 0; i < V; i++) {
        if (result[i] == INT_MAX) {
            cout << "Node " << i << ": Unreachable" << endl;
        } else {
            cout << "Node " << i << ": " << result[i] << endl;
        }
    }
    return 0;
}