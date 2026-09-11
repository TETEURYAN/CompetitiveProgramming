#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        char buf[105];
        scanf("%s", buf);
        string s(buf);
        
        int runs = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) runs++;
        }
        
        int ans;
        if (runs == 1) ans = 1;
        else if (runs == 2) ans = 2;
        else ans = 1;
        
        printf("%d\n", ans);
    }
    return 0;
}
