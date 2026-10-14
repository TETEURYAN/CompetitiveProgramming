#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        long long mx=a[0], mn=a[0]; 
        long long ans=a[0];

        for (int i=1;i<n;i++) {
            ans = max(ans, a[i] + max(mx, -mn));

            long long nmx = max({a[i], mx + a[i], 2 * mx + a[i]});
            long long nmn = min({a[i], mn + a[i], 2 * mn + a[i]});
            mx = nmx;
            mn = nmn;
        }
        cout << ans << "\n";
    }
    return 0;
}
