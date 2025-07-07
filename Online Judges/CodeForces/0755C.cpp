#include <bits/stdc++.h>
using namespace std;

#define int long long

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(adj, visited, v);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<vector<int>> arr(n);         
    vector<bool> visited(n, false);     

    for(int i = 0; i < n; i++){
        int u;
        cin >> u;
        u--; 
        arr[i].push_back(u);
        arr[u].push_back(i);
    }

    int c = 0;
    for(int i = 0; i < n; i++){ 
        if(!visited[i]){
            dfs(arr, visited, i);
            c++;
        }
    }

    cout << c << endl;

    return 0;
}
