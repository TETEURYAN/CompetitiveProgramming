#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> tree[MAXN];
int parent[MAXN];
int height[MAXN];
bool visited[MAXN];
pair<int, int> grafos[MAXN];

void dfs(int u, int p) {
    height[u] = 1;
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs(v, u);
        height[u] = max(height[u], height[v] + 1);
    }
}

void dfs_2(int u) {
    visited[u] = true;
    int next = -1, max_height = 0;
    for (int v : tree[u]) {
        if (not visited[v] and height[v] > max_height) {
            max_height = height[v];
            next = v;
        }
    }
    if (next != -1)
        dfs_2(next);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 2; i <= n; ++i) {
        cin >> parent[i];
        tree[parent[i]].push_back(i);
        tree[i].push_back(parent[i]);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        grafos[i] = {height[i], i};
    }

    sort(grafos + 1, grafos + n + 1, greater<>()); 

    long long ans = 0;
    for (int i = 1; i <= n and k > 0; ++i) {
        int u = grafos[i].second;
        if (not visited[u]) {
            ans += grafos[i].first;
            dfs_2(u);
            k--;
        }
    }

    cout << ans << '\n';
    return 0;
}
