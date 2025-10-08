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
