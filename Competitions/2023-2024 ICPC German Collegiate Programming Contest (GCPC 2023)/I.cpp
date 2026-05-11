#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> pos(n + 1); 
    set<int> fill;      

    int max_pad = 0;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
        fill.insert(pos[i]);
        max_pad = max(max_pad, pos[i]);
    }


    set<int> place;
    for (int p = 1; p <= max_pad + 1000000; p++) { 
        if (fill.find(p) == fill.end()) {
            place.insert(p);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int i;
        cin >> i;
        int curr = pos[i];

        auto it = place.upper_bound(curr);
        int asn = *it;

        cout << asn << "\n";

        place.erase(it);
        place.insert(curr); 
        pos[i] = asn;              
    }

    return 0;
}
