    #include <bits/stdc++.h>
    using namespace std;
     
    void solve(){
        string s;
        cin >> s;
     
        int n = s.size();
        int pos = n;
        for(int i = (n-1); i >= 0; i--){
            if((s[i] - '0') >= 5){
                if(i == 0){
                    s = '1' + s;
                    pos = i + 1;
                }
                else{
                    s[i-1]++;
                    pos = i;
                }
            }
        }
     
        for(int j = pos; j < n+1; j++){
            s[j] = '0';
        }
        cout << s << endl;
    }
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t;
        cin >> t;
     
        while(t--)
            solve();
    }
