#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<int64_t> v(100000);
    int n; 
    int64_t nn = 0, cost = 0; 
    cin >> n; 
    for(int i = 0; i < n; i++)
        cin >> v[i];

    bool tiaz = false;
    for(int i = 0; i < n; i++){
        if(v[i] > 0){
            cost += abs(v[i]-1);
        }else{
            cost += abs(-1-v[i]);
            nn++;
        }
        if(v[i] == 0) tiaz = true;
    }
    if(nn % 2 == 0) cout << cost << endl;
    else if(tiaz) cout << cost << endl;
    else cout << cost + 2 << endl;
    return 0;
}
