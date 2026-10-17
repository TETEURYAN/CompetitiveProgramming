#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        
        cin >> n >> s;
        
        int k = 0, mn = n, mx = -1;
        for (int i=0;i<n;i++) {
            if (s[i]=='1'){
                k++;
                mn = min(mn,i);
                mx = max(mx,i);
            }
        }
        if (k == 1) cout << 0 << "\n";
        else if (k == 2) cout << 1 << "\n";
        else cout << mx - mn << "\n";
    }
    return 0;
}
