#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;
        
        cout << (m-c) + (n-r)*m + (n-r)*(m-1) << "\n";   
    }
    
    return 0;
}
