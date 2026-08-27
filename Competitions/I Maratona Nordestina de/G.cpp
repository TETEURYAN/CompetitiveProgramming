#include<bits/stdc++.h> 

using namespace std;

using ll = long long;

signed main(){
   ll q;
   cin >> q;

   deque<ll> fila;
    
   ll conta = 0;
   ll contb = 0;
   ll ans = 0;

   for(ll i=0;i<q;i++){
      ll n;
      char c;

      cin >> n;

      if(n == 1 or n == 2)cin >> c;

      if(n == 1){
        fila.push_back(c);

        if(c == 'A'){
          conta++;
        }else if(c == 'B'){
          ans += conta;
          contb++;
        }
      }else if(n == 2){
        fila.push_front(c);

        if(c == 'A'){
          conta++;
          ans += contb;
        }else if(c == 'B'){
          contb++;
        }
      }else if(n == 3){
        if(fila.back() == 'A'){
          conta--;
        }else{
          ans -= conta;
          contb--;
        }
        fila.pop_back();
      }else if(n == 4){
        if(fila.front() == 'A'){
          ans -= contb;
          conta--;
        }else{
          contb--;
        }
        fila.pop_front();
      }

      cout << ans << endl;
  }

}
