#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long int
#define endl '\n'
#define pb push_back
#define pi pair<int, int>
#define pii pair<pi, int>
#define fir first
#define sec second
#define MAXK 100001
#define mod 10000007
#define INF 1e9

int x, y, n, d, k, m, t;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    bool change = true;
    while(change){
      change = false;
      for(int i = 1; i < (long) s.size(); i++){
        if((s[i-1]-'0') < (s[i]-'0')-1){
          s[i]=s[i]-'1'+'0';
          swap(s[i], s[i-1]);
          change = true;
        }
      }
    }

    cout << s << endl;
  }
}
