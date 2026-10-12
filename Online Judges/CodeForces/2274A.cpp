#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
            
        cin >> n;
        
        ll alt = 0;
        for (int i=1;i<=n;i++){
            ll a;
            
            cin >> a;
            
            if ((n-i)%2==0) alt+=a;
            else alt-=a;
        }
        if (n %2== 0) alt= -alt;
        printf("%lld\n", alt);
    }
    return 0;
}
