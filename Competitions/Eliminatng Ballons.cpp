#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, total = 0;
    cin >> n;
    vector<int> balloons(n);
    for(int i = 0; i < n; i++){
        cin >> balloons[i];
    }

    unordered_map<int, int> arrows;
    for(int height : balloons){
        if(arrows[height] > 0) {
            arrows[height]--;
            arrows[height - 1]++;
        } else {
            total++;
            arrows[height - 1]++;
        }
    }

    cout << total << endl;
    return 0;
}
