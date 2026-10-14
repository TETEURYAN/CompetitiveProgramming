#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        ll k;
        
        cin >> n >> k;
      
        vector<ll> s(n), m(n);
        ll mn = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            ll a, b, c;
            
            cin >> a >> b >> c;
            
            s[i] = a + b + c;
            
            mn = min(mn, s[i]);
            if (a <= b && b <= c) {
                if (a == b && b == c) m[i] = -1;          
                else m[i] = min(b - a, c - b) + 1;        
            } else {
                m[i] = 0;                                  
            }
        }
        auto ok = [&](ll S) {
            ll total = 0;
            for (int i = 0; i < n; i++) {
                if (S <= s[i]) continue;
                if (m[i] < 0) return false;
                total += S - s[i] + 2 * m[i];
                if (total > k) return false;
            }
            return true;
        };
        ll lo = mn, hi = mn + k;
        while (lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            if (ok(mid)) lo = mid;
            else hi = mid - 1;
        }
        
        cout << lo << endl;
        
    }
    return 0;
}
