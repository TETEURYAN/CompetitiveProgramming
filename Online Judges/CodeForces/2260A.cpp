#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int z = 0; 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) z++;
        }

        int ans;
        if (n == 1) {
            ans = (a[0] == 0) ? 0 : -1;
        } else {
            bool e0 = (a[0] == 0);
            bool e1 = (a[n - 1] == 0);

            if (e0 and e1) {
                ans = 0;
            } else if (e0 != e1) {
                ans = (z >= 2) ? 1 : -1;
            } else { 
                ans = (z >= 2) ? 2 : -1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
