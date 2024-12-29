#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    string allOp[n];

    for (int i = 0; i < n; i++)
    {
        cin>>allOp[i];
    }
    

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int pl =0;
        int mn =0;
        bool ch = false;
        for (char c : allOp[i])
        {
           if (c=='+') pl++; 
           if (c=='-') mn++; 
           if (c=='x' || c=='X') ch = true; 
        }
        
        if(pl==2 && ch){
            sum++;
        } else if(mn==2 && ch){
            sum--;
        }
    }
    cout<<sum;
    return 0;
}
