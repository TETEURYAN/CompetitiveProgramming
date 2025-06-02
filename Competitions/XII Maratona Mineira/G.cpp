#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, ll>;

const ll INF = 1e18;

int n, c, p;
vector<vector<pii>> car, ped;
vector<vector<ll>> dist;

struct State {
    int v, mode;
    ll cost;
    State(int _v, int _m, ll _c) : v(_v), mode(_m), cost(_c) {}
    bool operator>(const State &o) const { return cost > o.cost; }
};

ll dijkstra_state() {
    for (int i = 1; i <= n; ++i)
        dist[i][0] = dist[i][1] = dist[i][2] = INF;

    priority_queue<State, vector<State>, greater<State>> pq;
    dist[1][0] = 0;
    pq.emplace(1, 0, 0);

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();
        int u = cur.v, m = cur.mode;
        ll d = cur.cost;

        if (d > dist[u][m]) continue;

        if (m == 0 || m == 2) {
            for (auto &[v, w] : ped[u]) {
                if (dist[v][m] > d + w) {
                    dist[v][m] = d + w;
                    pq.emplace(v, m, dist[v][m]);
                }
            }
        }

        if (m == 0) {
            if (dist[u][1] > d) {
                dist[u][1] = d;
                pq.emplace(u, 1, d);
            }
        }

        if (m == 1) {
            if (dist[u][2] > d) {
                dist[u][2] = d;
                pq.emplace(u, 2, d);
            }
        }

        if (m == 1) {
            for (auto &[v, w] : car[u]) {
                if (dist[v][1] > d + w) {
                    dist[v][1] = d + w;
                    pq.emplace(v, 1, dist[v][1]);
                }
            }
        }
    }

    return min({dist[n][0], dist[n][1], dist[n][2]});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c >> p;
    car.assign(n + 1, {});
    ped.assign(n + 1, {});
    dist.assign(n + 1, vector<ll>(3, INF));

    for (int i = 0; i < c; ++i) {
        int a, b; ll w;
        cin >> a >> b >> w;
        car[a].emplace_back(b, w);
    }

    for (int i = 0; i < p; ++i) {
        int a, b; ll w;
        cin >> a >> b >> w;
        ped[a].emplace_back(b, w);
        ped[b].emplace_back(a, w);
    }

    ll ans = dijkstra_state();
    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}
