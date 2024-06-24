#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class DSU {
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

std::vector<Edge> kruskal(int n, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end());
    DSU dsu(n);
    std::vector<Edge> mst;

    for (const auto& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unionSets(edge.u, edge.v);
            mst.push_back(edge);
        }
    }

    return mst;
}

int main() {
    int nodes, edgesCnt;
    cin >> nodes >> edgesCnt;
    vector<Edge> edges;
    for (int i = 0; i < edgesCnt; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }
    vector<Edge> mst = kruskal(nodes, edges);

    for (const auto& edge : mst) {
        std::cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }

    return 0;
}