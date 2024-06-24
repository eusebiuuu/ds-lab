#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

vector<vector<Edge>> graph;

void prim(int n) {
    std::vector<bool> inMST(n + 1, false);
    std::priority_queue<Edge, std::vector<Edge>, std::greater<>> pq;
    int start = 1;
    inMST[start] = true;

    for (const auto &edge : graph[start]) {
        pq.push(edge);
    }

    while (!pq.empty()) {
        int node1 = pq.top().u, node2 = pq.top().v, currW = pq.top().weight;
        pq.pop();

        if (inMST[node1] and inMST[node2]) continue;
        cout << node1 << ' ' << node2 << ' ' << currW << '\n';
        if (inMST[node1]) {
            swap(node1, node2);
        }
        inMST[node1] = true;

        for (const auto& edge : graph[node1]) {
            if (!inMST[edge.v]) {
                pq.push(edge);
            }
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    graph.resize(nodes + 1);
    for (int i = 0; i < edges; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({a, b, w});
        graph[b].push_back({b, a, w});
    }
    prim(nodes);
    return 0;
}
