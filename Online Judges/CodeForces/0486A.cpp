#include <bits/stdc++.h>

using namespace std;

int main ()
{
    long long int n;
    cin >> n;
    
    if (n & 1)
    {
        cout << -(n/2 + 1) << '\n';
    }
    else
    {
        cout << n/2 << '\n';
    }
    
    return 0;
}
