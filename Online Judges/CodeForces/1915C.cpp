    #include <bits/stdc++.h>
    using namespace std;
    #define lli unsigned long long int
     
    void solve() {
    	lli a, b = 0;
    	cin >> a;
    	while(a > 0){
    		int s;
    		cin >> s;
    		// cout << s << endl;
    		b += s;
    		a--;
    	}
    	lli sq = sqrt(b);
    	
    	// cout << b << " <-numero | rais -> " << sq << endl;
    	printf("%s\n", (sq*sq) == b  ? "YES" : "NO");
    }
     
    int main(){
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
    	int t;
    	cin >> t;
     
    	while(t--){
    		solve();
    	}
     
        return 0;
    }
