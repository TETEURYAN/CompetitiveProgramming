#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
using ll = long long;
using ld = long double;

void SOL()
{   
    int n;
    cin >> n;
    map<pair<int , int> , bool> mp;
    for(int i = 0 ; i < n ; i++) {
        int x , y;
        cin >> x >> y;
        mp[{x,y}] = true;
    }
    int ans = 0;
    for(int x = 0 ; x <= n ; x++) {
        if(mp[{x,0}] and mp[{x, 1}]) {
            ans += n - 2;
        }
        if(mp[{x,0}] and mp[{x-1 , 1}] and mp[{x+1 , 1}])
            ans++;
        if(mp[{x,1}] and mp[{x-1 , 0}] and mp[{x+1 , 0}])
            ans++;
    }
    cout<<ans<<"\n";
 
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    testCases
    SOL();
    return 0;
}
