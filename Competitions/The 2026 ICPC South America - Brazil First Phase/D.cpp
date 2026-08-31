#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> a;

bool checkRotate180(){
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(a[i][j] != a[N-1-i][M-1-j]) return false;
    return true;
}
bool checkFlipH(){
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(a[i][j] != a[i][M-1-j]) return false;
    return true;
}
bool checkFlipV(){ 
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(a[i][j] != a[N-1-i][j]) return false;
    return true;
}
bool checkRot90(){ // requer N==M
    int n=N;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j] != a[n-1-j][i]) return false;
    return true;
}
bool checkRot270(){ // requer N==M
    int n=N;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j] != a[j][n-1-i]) return false;
    return true;
}
bool checkTranspose(){ // requer N==M
    int n=N;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j] != a[j][i]) return false;
    return true;
}
bool checkAntiTranspose(){ // requer N==M
    int n=N;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j] != a[n-1-j][n-1-i]) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    a.resize(N);
    for(int i=0;i<N;i++) cin >> a[i];

    int cnt = 1; 
    if(checkRotate180()) cnt++;
    if(checkFlipH())     cnt++;
    if(checkFlipV())     cnt++;
    if(N==M){
        if(checkRot90())         cnt++;
        if(checkRot270())        cnt++;
        if(checkTranspose())     cnt++;
        if(checkAntiTranspose()) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}
