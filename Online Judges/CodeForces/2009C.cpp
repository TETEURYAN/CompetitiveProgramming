    #include<bits/stdc++.h>

    using namespace std;

    typedef long long ll;
     
    int main() {
    	int t; cin >> t;
    	while (t--) {
    		ll x, y, k;
    		cin >> x >> y >> k;
    		ll mx = max(x, y);
    		ll ans = mx / k + (mx % k != 0);
    		ans *= 2;
    		if ((x + k - 1) / k > (y + k - 1) / k) ans--;
    		cout << ans << "\n";
    	}
    	return 0;
    }
