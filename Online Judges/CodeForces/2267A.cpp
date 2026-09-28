#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        char c;
        string s;
        cin >> n >> c >> s;

        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            char a = s[i], b = s[n - 1 - i];
            if (a == b) continue;
            if (a == c || b == c) ans += 1;
            else ans += 2;
        }
        cout << ans << "\n";
    }
    return 0;
}
