        #include<bits/stdc++.h>
         
        using namespace std;
         
        int main(){
            ios_base::sync_with_stdio(false);
         
            cin.tie(NULL);
            bool ans = false;
         
            int n, m;
            cin >> n >> m;
        
            if(n<m){
                if((n%3)!=0){
                    if(m-1 == n){
                        ans = true;
                    }
                }
            }
            printf("%s\n", ans ? "Yes" : "No");
        }

