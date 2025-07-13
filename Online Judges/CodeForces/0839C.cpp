#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<vector<int>> adj(MAXN);
vector<bool> visited(MAXN, false);

double dfs(int u) {
    visited[u] = true;
    int children = 0;
    double sum = 0.0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            sum += dfs(v) + 1; 
        }
    }

    if (children == 0) return 0.0;

    return sum / children;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << fixed << setprecision(15);
    cout << dfs(1) << endl;

    return 0;
}
