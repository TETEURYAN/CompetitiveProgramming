#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        for (int i = 1; i < 2*n; i+=2)
        {
            cout << i << " \n"[i == 2*n - 1];
        }
        
    }
    
    return 0;
}
