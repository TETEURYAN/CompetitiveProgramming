#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, q, index=0;
    cin >> n >> q;

    char c[n];

    cin >> c;
    for(int i = 0; i < q; i++){
        int query, x;
        cin >> query >> x;
        if(query == 2){
            int cindex =(x-1-index);
            if(cindex<0){
                
                cindex = n+cindex;
            }
            cout << c[cindex] << endl;
        }else{
            index+=x;
            index=index%n;
        }
    }
}
