    #include <bits/stdc++.h>
    using namespace std;
     
    void solve() {
    	int str[3] = {0};
    	for (int i = 0; i < 9; i++) {
    		char c;
    		cin >> c;
    		if (c != '?') str[c - 'A']++;
    	}	
    	for (int i = 0; i < 3; i++) 
    		if (str[i] < 3) cout << (char)('A' + i) << endl;
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
