#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<ll> parent, rank;
    DSU(ll n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    ll find_set(ll v) {
        if (v != parent[v])
            parent[v] = find_set(parent[v]);
        return parent[v];
    }
    void union_sets(ll a, ll b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        dsu.union_sets(u, v);
    }

    set<ll> comps;
    for (ll i = 0; i < n; i++)
        comps.insert(dsu.find_set(i));
    ll C = comps.size();

    string yes = "BOM";
    string no = "RUIM";

    if (C == 1 and m == n - 1) {
        cout << yes << "\n";
    } else {
        ll dest = m - (n - C);
        ll build = C - 1;
        cout << no << " " << dest << " " << build << "\n";
    }
}
