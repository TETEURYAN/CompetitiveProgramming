#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n+1);
        
         for(int i = 1; i <= n; i++) cin >> p[i]; 
        
        vector<int> S;
        for(int i = 1; i <= n; i++){
            if(p[i] != i) S.push_back(i);
        }
        
        int m = S.size();
        bool ok = true;
        
      
        for(int k = 0; k < m; k++){
            int mirr = S[m - 1 - k]; 
            int ans = S[k];            
            if(p[mirr] != ans){
                ok = false;
                break;
            }
        }
        
        cout << (ok ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
