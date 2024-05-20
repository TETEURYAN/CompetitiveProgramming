#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
typedef vector<long long> vi;


const int INF = INT_MAX;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,x;
    cin >> n >> x;

    vi arr(n);
    vi dp(x+1, INT_MAX);

    for(auto & i : arr) cin >> i;

    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n;j++){
            if(i - arr[j] >= 0 and dp[i - arr[j]] != INF){
                if(dp[i] > dp[i-arr[j]] + 1){
                    dp[i] = dp[i-arr[j]] + 1;
                }
            }
        }
    }
    cout << (dp[x] != INF ? dp[x] : -1) << nl

    return 0;

}
/*

3 11
1 5 7

*/
