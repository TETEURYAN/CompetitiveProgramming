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
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        int ans = 0;
        for (int b = 30; b >= 0; b--) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if ((a[i] >> b) & 1) cnt++;
            }
            if (cnt == n) {
                ans |= (1 << b);
            } else if (cnt == 0) {
                // ninguem tem o bit, ignora
                continue;
            } else {
                ans |= (1 << (b + 1)) - 1;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
