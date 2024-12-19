#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define pb push_back
#define int long long int
#define mp make_pair
#define pi pair<int, int>
#define pii pair<pi, int>
#define fir first
#define sec second
#define MAXN 100001
#define MAXL 100
#define mod 1000000007

vector<int> divs(int x) {
    vector<int> div;
    x = abs(x);
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            div.pb(i);
            div.pb(-i);
            if (i != x / i) {
                div.pb(x / i);
                div.pb(-(x / i));
            }
        }
    }
    return div;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int sumA = accumulate(a.begin(), a.end(), 0ll);
    int sumB = accumulate(b.begin(), b.end(), 0ll);

    vector<int> possiveis_a, possiveis_b;
    for (int i = 0; i < n; i++) {
        possiveis_a.pb(sumA - a[i]);
    }
    for (int i = 0; i < m; i++) {
        possiveis_b.pb(sumB - b[i]);
    }

    sort(possiveis_a.begin(), possiveis_a.end());
    sort(possiveis_b.begin(), possiveis_b.end());

    while (q--) {
        int x;
        cin >> x;
        bool f = false;
        vector<int> d = divs(x);
        for (int d1 : d) {
            int d2 = x / d1;

            if (binary_search(possiveis_b.begin(), possiveis_b.end(), d1) &&
                binary_search(possiveis_a.begin(), possiveis_a.end(), d2)) {
                f = true;
                break;
            }
        }
        cout << (f ? "Yes\n" : "No\n");
    }
    return 0;
}
