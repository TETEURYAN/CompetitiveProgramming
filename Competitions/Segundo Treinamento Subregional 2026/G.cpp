#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int MAX = 26;
vector<int> g[MAX];

vector<int> topo_sort(int n) {
	vector<int> ret(n,-1), vis(n,0);
	
	int pos = n-1, dag = 1;
	function<void(int)> dfs = [&](int v) {
		vis[v] = 1;
		for (auto u : g[v]) {
			if (vis[u] == 1) dag = 0;
			else if (!vis[u]) dfs(u);
		}
		ret[pos--] = v, vis[v] = 2;
	};

	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	if (!dag) ret.clear();	
	return ret;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    vector<string> arr(t);
    for(auto &x : arr) cin >> x;
    
    for(int i = 0; i < t-1; i++){
        string s = arr[i];
        string t2 = arr[i+1];

        int len = min(s.size(), t2.size());
        bool found = false;

        for(int j = 0; j < len; j++){
            if(s[j] != t2[j]){
                g[s[j]-'a'].push_back(t2[j]-'a');
                found = true;
                break;
            }
        }

        if(!found && s.size() > t2.size()){
            cout << "Impossible\n";
            return 0;
        }
    }

    vector<int> ans = topo_sort(26);

    if(ans.empty()){
        cout << "Impossible\n";
    } else {
        for(int x : ans){
            cout << char(x + 'a');
        }
        cout << "\n";
    }
    
    return 0;

}
