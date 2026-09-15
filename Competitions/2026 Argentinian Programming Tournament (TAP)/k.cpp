#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int r;
        cin >> r;

        cout << (5 * r) % 9 << ' ';
    }

    cout << '\n';

    return 0;
}
