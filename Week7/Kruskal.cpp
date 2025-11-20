#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

class Graph {
private:
    vector<Edge> G;
    vector<Edge> MST;
    vector<int> parent;
    int n;
public:
    Graph(int n): n(n), parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void addEdge(int u, int v, int w) {
        G.push_back({u, v, w});
    }

    int findSet(int i) {
        if (i == parent[i]) {
            return i;
        }
        return findSet(parent[i]);
    }

    void unionSet(int u, int v) {
        parent[u] = v;
    }

    void kruskal() {
        sort(G.begin(), G.end());
        for (auto &e : G) {
            int ru = findSet(e.u);
            int rv = findSet(e.v);
            if (ru != rv) {
                MST.push_back(e);
                unionSet(ru, rv);
            }
        }
    }

    void print() {
        cout << "Edge : Weight\n";
        for (auto &e : MST) {
            cout << e.u << " - " << e.v << " : " << e.w << "\n";
        }
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(2, 3, 4);

    g.kruskal();
    g.print();
}
