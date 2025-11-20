#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(int u, vector<bool>& visited, const vector<vector<int>>& adj) {
    stack<int> s;
    s.push(u);
    while (!s.empty()) {
        int e = s.top();
        s.pop();
        if (!visited[e]) {
            visited[e] = true;
            cout << e << " ";
            for (int v: adj[e]) {
                s.push(v);
            }
        }
    }
}

void BFS(int s, vector<bool>& visited, const vector<vector<int>>& adj) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v: adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n = 6; 
    vector<vector<int>> adj(n);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);

    cout << "DFS using stack: ";
    vector<bool> visited_dfs(n, false);
    DFS(0, visited_dfs, adj);
    cout << endl;

    cout << "BFS using queue: ";
    vector<bool> visited_bfs(n, false);
    BFS(0, visited_bfs, adj);
    cout << endl;
}