#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX;

// {peso, destino}
using Edge = pair<ll, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);    // grafo original
    vector<vector<Edge>> reversed(n); // grafo com arestas invertidas

    for (int i = 0; i < m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a--; b--;

        graph[a].push_back({w, b});   // a → b
        reversed[b].push_back({w, a}); // b → a (invertido)
    }

    int source = 0;     // origem
    int target = n - 1; // destino

    // Dijkstra genérico
    auto dijkstra = [&](int start, vector<vector<Edge>>& g) {
        vector<ll> dist(n, INF);
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if (d > dist[u]) continue; // entrada obsoleta

            for (auto [w, v] : g[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    };

    // distS[v] = menor caminho de source até v  (grafo original)
    vector<ll> distS = dijkstra(source, graph);

    // distT[v] = menor caminho de v até target  (grafo invertido)
    vector<ll> distT = dijkstra(target, reversed);

    // Exemplo de uso: menor caminho passando por algum nó intermediário v
    // custo = distS[v] + distT[v]
    ll best = INF;
    for (int v = 0; v < n; v++) {
        if (distS[v] != INF && distT[v] != INF) {
            best = min(best, distS[v] + distT[v]);
        }
    }

    cout << "Menor caminho de 1 a " << n << ": " << best << "\n";

    // Imprime distâncias individuais
    for (int v = 0; v < n; v++) {
        cout << "No " << v + 1 << ":"
             << "  distS = " << (distS[v] == INF ? -1 : distS[v])
             << "  distT = " << (distT[v] == INF ? -1 : distT[v])
             << "\n";
    }

    return 0;
}
