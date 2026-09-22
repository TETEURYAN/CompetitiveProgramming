#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, ll val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    ll sum(int idx) const {
        ll res = 0;

        for (; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
        }

        return res;
    }

    ll rangeSum(int l, int r) const {
        return sum(r) - sum(l);
    }
};

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<int> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    reverse(p.begin(), p.end());

    Fenwick bit(n);
    set<int> imp;

    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
        int k = p[i];
        auto it = imp.upper_bound(k);

        int champion;

        if (it == imp.begin()) {
  
            imp.insert(k);
            champion = k;
        } else {
            int left = *prev(it);

            ll accumulated = bit.rangeSum(left, k);

            if (accumulated < a[k]) {

                imp.insert(k);
                champion = k;
            } else {
                champion = left;
            }
        }

        bit.add(k, a[k]);

        while (true) {
            auto nextIt = imp.upper_bound(k);

            if (nextIt == imp.end()) {
                break;
            }

            int j = *nextIt;

            ll accumulated = bit.rangeSum(champion, j);

            if (accumulated < a[j]) {
                break;
            }
            imp.erase(j);
        }
        ans[n - 1 - i] = (int)imp.size() - 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i + 1 == n ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
