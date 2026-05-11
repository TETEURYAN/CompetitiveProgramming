#include <bits/stdc++.h>
using namespace std;

void solve(const string& s, int i, string cur) {
    int n = s.size();

    if (i == n) {
        cout << cur << '\n';
        return;
    }

    solve(s, i + 1, cur + (char)tolower(s[i]));

    if (i + 1 < n && s[i] == 'S' && s[i + 1] == 'S') {
        solve(s, i + 2, cur + 'B');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    solve(s, 0, "");

    return 0;
}
