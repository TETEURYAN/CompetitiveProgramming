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
        vector<int> diff(n + 2, 0);
        for (int k = 1; k <= n; k++) {
            long long a;
            cin >> a;
            long long l = a * k;
            if (l <= n - 1) {
                long long r = min<long long>(n - 1, l + k - 1);
                diff[l]++;
                diff[r + 1]--;
            }
        }
        vector<int> res;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            if (cur == 0) res.push_back(i);
        }
        cout << res.size() << "\n";
        for (int x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
