#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> arr;
    int a, n, ans = 0;

    cin >> n;

    arr.resize(n);

    for(int &i : arr)
        cin >> i;

    for(int i = 0; i < n; i++)
        if(arr[i] != arr[i+1])
            ans++;    

    cout << ans << endl;        

}