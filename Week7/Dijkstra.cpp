#include<iostream>
#include<vector>
using namespace std;

int minDist(const vector<int>& dist, const vector<bool>& check, int V) {
    int min = INT_MAX;
    int min_idx = -1;
    for (int v = 0; v < V; v++) {
        if (check[v] == false && dist[v] <= min) {
            min = dist[v];
            min_idx = v;
        }
    }
    return min_idx;
}

void print(const vector<int>& dist) {
    cout << "Shortest distance of vertices from source: " << endl;
    for (int i = 0; i < dist.size(); i++) {
        cout << i << ": " << dist[i] << endl;
    }
}

void dijkstra(const vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    vector<bool> check(V, false);
    dist[src] = 0;
    for (int count = 0; count < V-1; count++) {
        int u = minDist(dist, check, V);
        check[u] = true;
        for (int v = 0; v < V; v++) {
            if (!check[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    print(dist);
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter distance between vertices based on graph[start][end] on matrix " << V << "x" << V << " : " << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    dijkstra(graph, 0, V);
}