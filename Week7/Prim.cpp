#include<bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;

    Graph(int v_): V(v_) {
        for (int i = 0; i < V; i++) {
            vector<int> row;
            for (int j = 0; j < V; j++) {
                row.push_back(0);
            }
            adj.push_back(row);
        }
    }
};

void prim(const Graph& g) {
    int V = g.V;
    vector<int> selected;
    for (int i = 0; i < V; i++) {
        selected.push_back(0);
    }
    int edge_cnt = 0;
    selected[0] = 1;
    while (edge_cnt < V - 1) {
        int minW = INT_MAX;
        int x = -1;
        int y = -1;
        for (int i = 0; i < V; i++) {
            if (selected[i] == 1) {
                for (int j = 0; j < V; j++) {
                    if (selected[j] == 0 && g.adj[i][j] != 0) {
                        if (g.adj[i][j] < minW) {
                            minW = g.adj[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " : " << g.adj[x][y] << endl;
        selected[y] = 1;  
        edge_cnt++;
    }
}

int main() {
    Graph g(5);

    g.adj[0][1] = 9; g.adj[1][0] = 9;
    g.adj[0][2] = 75; g.adj[2][0] = 75;
    g.adj[1][2] = 95; g.adj[2][1] = 95;
    g.adj[1][3] = 19; g.adj[3][1] = 19;
    g.adj[1][4] = 42; g.adj[4][1] = 42;
    g.adj[2][3] = 51; g.adj[3][2] = 51;
    g.adj[2][4] = 66; g.adj[4][2] = 66;
    g.adj[3][4] = 31; g.adj[4][3] = 31;

    cout << "Edges in MST:\n";
    prim(g);
}


