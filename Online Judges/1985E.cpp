

    #include <bits/stdc++.h>
    using namespace std; 
    #define pb push_back
    using vi = vector<int>;
    using ll = long long;
    using vll = vector<ll>;
     
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            ll x, y, z, k;
            cin >> x >> y >> z >> k;
     
            ll max_ways = 0;
     
            for (ll a = 1; a * a * a <= k; ++a) {
                if (k % a == 0) {
                    for (ll b = a; b * b <= k / a; ++b) {
                        if ((k / a) % b == 0) {
                            ll c = k / (a * b);
                            if (a <= x && b <= y && c <= z) {
                                max_ways = max(max_ways, (x - a + 1) * (y - b + 1) * (z - c + 1));
                            }
                            if (a <= x && c <= y && b <= z) {
                                max_ways = max(max_ways, (x - a + 1) * (y - c + 1) * (z - b + 1));
                            }
                            if (b <= x && a <= y && c <= z) {
                                max_ways = max(max_ways, (x - b + 1) * (y - a + 1) * (z - c + 1));
                            }
                            if (b <= x && c <= y && a <= z) {
                                max_ways = max(max_ways, (x - b + 1) * (y - c + 1) * (z - a + 1));
                            }
                            if (c <= x && a <= y && b <= z) {
                                max_ways = max(max_ways, (x - c + 1) * (y - a + 1) * (z - b + 1));
                            }
                            if (c <= x && b <= y && a <= z) {
                                max_ways = max(max_ways, (x - c + 1) * (y - b + 1) * (z - a + 1));
                            }
                        }
                    }
                }
            }
     
            cout << max_ways << "\n";
        }
    }
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        solve();
        return 0;
    }
