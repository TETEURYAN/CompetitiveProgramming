#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
 
using namespace std;
 
typedef long long ll;         // Define a name for long long ll
typedef vector<ll> vi;        // Define vi as vector<ll>
typedef vector<vi> vvi;       // Define vvi as vector of vector<ll>
typedef pair<ll, ll> pii;     // Define pii as pair<ll, ll>
typedef map<ll, ll> mii;      // Define mii as map<ll, ll>
 
void solve(){
    ll shelves, brand;
    cin >> shelves >> brand;
 
    mii mp;
 
    for (ll i = 0; i < brand; i++) {
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }
 
    vi arr;
 
    for (auto i: mp) {
        arr.push_back(i.second);
    }
 
    sort(arr.begin(), arr.end());
 
    ll cnt = 0;
    ll i = arr.size() - 1;
 
    for (ll j = 0; j < shelves && i >= 0; j++, i--) {
        cnt += arr[i];
    }
 
    cout << cnt << endl;
}
 
int main() {
    ll t = 1;
    cin >> t;
 
    while (t--) solve();
 
    return 0;
}
