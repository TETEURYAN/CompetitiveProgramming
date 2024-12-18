#include <bits/stdc++.h>

using namespace std;

void solved()
{
    long long int m, a, b, c, sum;

    cin >> m >> a >> b >> c;

    sum = min(a, m) + min(b, m) + min(c, 2*m - min(a, m) - min(b, m));

    cout << sum << '\n';
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--)
        solved();
        
    return 0;
}
