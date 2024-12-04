#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> s(2*n);
        int cnt = 0;
        for (int i = 0; i < 2*n; i++)
        {
            cin >> s[i];
            if (s[i] == 1) cnt++;
        }
        
        
        cout << (cnt&1) << ' ' << min(cnt, n*2 - cnt) << '\n';
    }
 
    return 0;
}20
