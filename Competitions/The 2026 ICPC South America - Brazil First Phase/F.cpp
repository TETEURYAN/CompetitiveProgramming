#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin >> N;

    ll pw = 1; 
    while (pw * 3 <= N) pw *= 3;

    ll boundary = 2 * pw;
    ll ans;
    if (N <= boundary) {
        ans = N + pw;
    } else {
        ans = 3 * (N - pw);
    }

    cout << ans << endl;
    return 0;
}
