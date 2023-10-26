    #include <bits/stdc++.h>
    using namespace std;
     
    bool paire(int a){
        return a%2;
    }
     
    void solve(){
        int n;
        cin >> n;
     
        int arr[n];
     
        for(auto &i : arr)
            cin >> i;
        
        int par = 0, impar = 0;
        for(int i = 0; i < n; i++){
            if(i%2 == true)
                par += arr[i];
            else
                impar += arr[i];    
        }
     
        if(paire(par) == paire(impar))
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;    
    }
     
    int main(){
        int t;
        cin >> t;
     
        while(t--)
            solve();
    }
