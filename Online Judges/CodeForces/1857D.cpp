#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int one[n];
    int two[n];

    for(int & i : one)
        cin >> i;
    for(int & i : two)
        cin >> i;
    
    int ans[n];
    for(int i = 0; i < n; i++)
        ans[i] = one[i] - two[i];

    int maximo = *max_element(ans, ans+n);  
    vector<int> result;

    for(int i = 0; i < n; i++)
        if(ans[i] == maximo)
            result.push_back(i+1);

    int strong = result.size();
    cout << strong << endl;

    for(int i : result)
        cout << i << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while(t--)
        solve();
}
