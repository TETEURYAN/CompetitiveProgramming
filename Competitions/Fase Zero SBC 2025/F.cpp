#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr) cin >> i;

    vector<unordered_map<int, int>> dp(5);
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int cnt = 3; cnt >= 0; --cnt) {
            for (auto [soma, calue] : dp[cnt]) {
                dp[cnt + 1][soma + arr[i]] += calue;
				// cout << calue << endl;
            }
        }
    }


    int q;
    cin >> q;
    while (q--) {
        int ans;
        cin >> ans;
        cout << dp[4][ans] << '\n';
    }

    return 0;
}
