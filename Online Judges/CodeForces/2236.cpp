#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(auto & i : a) cin >> i;
        
        sort(a.begin(), a.end(), greater<int>());
        
        vector<pair<int,long long>> groups;
        int i = 0;
        while(i < n){
            int j = i;
            while(j < n && a[j] == a[i]) j++;
            groups.push_back({a[i], (long long)(j - i)});
            i = j;
        }
        
        string ans = "NO";
        int m = groups.size();
        for(int idx = 0; idx < m; idx++){
            long long cnt = groups[idx].second;
            if(cnt % 2 == 0){
                ans = "YES";
                break;
            } else {
                if(idx + 1 < m && (long long)groups[idx].first - groups[idx+1].first <= k){
                    ans = "YES";
                    break;
                } else if(idx + 1 == m){
                    ans = "NO";
                    break;
                }
            }
        }
        
        printf("%s\n", ans.c_str());
    }
    return 0;
}
