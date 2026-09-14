#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, k;
    cin >> n >> k;
    
    long long a = (k + n - 1) / n; 
    long long b = k / 2;           
    
    if (a <= b) cout << "N" << "\n";
    else cout << "S" << "\n";
    
    return 0;
}
