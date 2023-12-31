    #include <bits/stdc++.h>
    using namespace std;
     
    int bits(int a, int b, int c){
    	return a^b^c;
    }
     
    int main(){
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
    	int t;
    	cin >> t;
     
    	while(t--){
    		int a,b,c;
    		cin >> a >> b >> c;
    		cout << bits(a,b,c) << endl;
    	}
     
        return 0;
    }
