#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string x;
        cin >> x;

        int k = x.size();
        long long y = 1;
        for (int i = 0; i < k; i++) y *= 10;
        y += 1;

        cout << y << "\n";
    }

    return 0;
}
