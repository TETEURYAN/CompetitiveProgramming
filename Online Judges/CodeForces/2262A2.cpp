#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> diff(n + 2, 0);
        vector<int> best(n, -1);          
        for (int k = 1; k <= n; k++) {
            long long a;
            cin >> a;
            long long l = a * k;
            if (l <= n - 1) {
                long long r = min<long long>(n - 1, l + k - 1);
                diff[l]++;
                diff[r + 1]--;
            }
            for (long long j = 0; j < a; j++) {
                long long L = j * k;
                if (L > n - 1) break;
                int R = (int)min<long long>(n - 1, L + k - 1);
                best[R] = max(best[R], (int)L);
            }
        }

        vector<long long> dp(n + 2, 0), pre(n + 3, 0);
        dp[0] = 1;
        pre[0] = 0;
        pre[1] = 1;                      

        int cur = 0;
        int M = -1;                      
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            if (cur == 0) {
                int lo = M + 1;          
                dp[i + 1] = ((pre[i + 1] - pre[lo]) % MOD + MOD) % MOD;
            } else {
                dp[i + 1] = 0;
            }
            pre[i + 2] = (pre[i + 1] + dp[i + 1]) % MOD;
            M = max(M, best[i]);         
        }

        int lo = M + 1;
        long long ans = ((pre[n + 1] - pre[lo]) % MOD + MOD) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
