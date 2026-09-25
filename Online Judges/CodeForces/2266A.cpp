#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a1, a2, a3;
        scanf("%d %d %d", &a1, &a2, &a3);
        int mn = min({a1, a2, a3});
        printf("%d\n", n - mn);
    }
    return 0;
}
