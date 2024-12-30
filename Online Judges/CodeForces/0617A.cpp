#include <bits/stdc++.h>
#define int long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define mp make_pair
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define _endl "\n"
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int gcd(int a, int b) { return (!b ? a : gcd(b, a % b)); }

void solve()
{
    int n;  cin >> n;
    cout << (n + 5 - 1) / 5;
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
