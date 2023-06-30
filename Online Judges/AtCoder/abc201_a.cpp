#include<bits/stdc++.h>

#define int long long int
#define endl '\n'
#define pb pushback
#define mod 1000007
//#define maxn 

using namespace std;
vector<int> arr(3);

signed main(){

    for(int &i : arr)  
        cin >> i;

    sort(arr.begin(), arr.end());

    int a = arr[2] - arr[1];
    int b = arr[1] - arr[0];

    if(a == b)
        cout << "Yes" << endl;
    else
    {
        cout << "No" << endl;
    }
                
}