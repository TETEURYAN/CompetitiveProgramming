#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> bfs(int start, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<ll> dist(n, LLONG_MAX);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            if (dist[v] == LLONG_MAX) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

pair<ll, ll> reduce(ll num, ll den) {
    ll g = gcd(num, den);
    return {num / g, den / g};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> holes(k);
    for (int i = 0; i < k; ++i) {
        cin >> holes[i];
        holes[i]--;
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<ll> distS = bfs(0, graph);
    vector<ll> distT = bfs(n - 1, graph);

    // Soma de distT para todos os wormholes
    ll S = 0;
    for (int w : holes) {
        S += distT[w];
    }

    ll minNum = distS[n - 1];
    ll minDen = 1;


    if (k > 1) {
        for (int w : holes) {
            ll num = (ll)(k - 1) * distS[w] + S - distT[w];
            ll den = k - 1;
           
            if (num * minDen < minNum * den) {
                minNum = num;
                minDen = den;
            }
        }
    }

    auto res = reduce(minNum, minDen);
    cout << res.first << "/" << res.second << "\n";
    return 0;
}
