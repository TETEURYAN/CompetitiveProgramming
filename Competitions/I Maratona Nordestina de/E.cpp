#include <bits/stdc++.h>

using namespace std;

signed main(){
  int n;
  cin >> n;

  int m = n;
  
  vector<int> arr(n);
  

  for(int i = 0; i < n; i++) arr[i] = i+1;

  while(arr.size() > 1){

    int m = arr.size();
    int t = (m + 2) / 3;
    
    vector<int> L(arr.begin(), arr.begin() + t);
    vector<int> R(arr.begin() + t, arr.begin() + 2*t);
    vector<int> Aside(arr.begin() + 2*t, arr.end());

    cout << "? " << t << " ";

    for(auto i : L) cout << i << " ";
    for(auto i : R) cout << i << " ";
  

    char ch;
    cin >> ch;

    if(ch == 'E'){ 
      arr = L;
    }else if(ch == 'D'){
      arr = R;
    }else{
      arr = Aside;
    }
  }

  cout << "! " << arr[0] << endl;
}
