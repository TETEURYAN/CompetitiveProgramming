#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> values;
vector<vector<int>> g;
int ans[MAXN];

void dfs(int u, int parent, vector<int> &seq) {
    int pos = lower_bound(seq.begin(), seq.end(), values[u]) - seq.begin();

    int old = -1;
    bool appended = false;

    if (pos == seq.size()) {
        seq.push_back(values[u]);
        appended = true;
    } else {
        old = seq[pos];
        seq[pos] = values[u];
    }

    ans[u] = seq.size();

    for (int v : g[u]) {
        if (v != parent) {
            dfs(v, u, seq);
        }
    }

    if (appended) {
        seq.pop_back();
    } else {
        seq[pos] = old;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    g.resize(n);
    values.resize(n);

    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<int> seq;
    dfs(0, -1, seq);

    for (int i = 1; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
