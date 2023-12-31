    #include <bits/stdc++.h>
    using namespace std;
    #define lli unsigned long long int
     
    void solve() {
    	int n;
    	cin >> n;
    	string s;
    	cin >> s;
    	string res = "";
    	while (not s.empty()) {
    		int x;
    		if (s.back() == 'a' or s.back() == 'e') x = 2;
    		else x = 3;
    		
    		while (x--) {
    			res += s.back();
    			s.pop_back();
    		}
    		res += '.';
    	}
    	res.pop_back();
    	reverse(res.begin(), res.end());
    	cout << res << '\n';
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
