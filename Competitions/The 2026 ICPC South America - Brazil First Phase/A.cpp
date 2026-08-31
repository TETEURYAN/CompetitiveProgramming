#include<bits/stdc++.h>

using namespace std;

using ll = long long;

signed main(){
    ll n;
    cin >> n;

    vector<ll> comp(n+1,0);
    vector<ll> vend(n+1,0);
    

      
    for(int i=1;i<=n;i++){
        ll a,b;
        cin >> a >> b;
        comp[i] = a + comp[i-1];
        vend[i] = b + vend[i-1];
    }

    ll q;
    cin >> q;

    vector<ll> query(q);
    vector<double> ans;
      
    for(auto & i : query) cin >> i;


    for(auto i : query){
      double sol = (double)(comp[i] - vend[i])/(comp[i] + vend[i]);
      ans.push_back(sol);
    }
    

    for(double i : ans){
      if(i > 0.0){
        cout << "COMPRA" << endl;
      }else if(i == 0.0){
        cout << "NEUTRO" << endl;
      }else{
        cout << "VENDA" << endl;
      }
    }

   return 0;
}
