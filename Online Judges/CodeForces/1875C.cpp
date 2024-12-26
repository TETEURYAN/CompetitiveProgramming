#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n,m;
    cin >> n >> m;
    int i = 0;
    long long result = 0;
    while (n != 0 && i < 1000) {
        if(n >= m){
            n %= m;
        }else{
            result += n;
            n *= 2;
        }
        i++;
    }
    n == 0 ? cout << result << endl : cout << -1 << endl;
}
int main(){
    int t;
    cin >> t;
    while (t--)
    solve();
}
