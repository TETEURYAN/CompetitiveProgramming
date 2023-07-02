    #include<bits/stdc++.h>
     
    using namespace std;
     
    int main(){
        ios_base::sync_with_stdio(false);
     
        cin.tie(NULL);
     
     
        int n, m;
        cin >> n >> m;
     
        vector<string> arr(n);
        vector<string> arrtwo(m);
        vector<int> yen(m+1);
        
        for(string &i : arr)
            cin >> i;
     
        for(string &i : arrtwo)
            cin >> i;
     
        for(int &i : yen)
            cin >> i;
     
        int ans = 0;
     
        for(int i = 0; i < n; i++){
            bool find = false;
            for(int j = 0; j < m; j++){
                if(arr[i] == arrtwo[j]){
                    ans+=yen[j+1];
                    find = true;
                }
            }
            if(not find) ans+=yen[0];
        }
     
        cout << ans;
        return 0;    
    }
