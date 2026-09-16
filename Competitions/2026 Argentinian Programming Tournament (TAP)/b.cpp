#include <bits/stdc++.h>
using namespace std;

bool vogal(char c) {
    return c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    
    set<string> candidates;
    
    for (int i = 1; i + 3 < n; i++) {
        if (s[i]=='G' && s[i+1]=='A' && s[i+2]=='S') {
            char before = s[i-1];
            char after = s[i+3];
            if (before == after && vogal(before)) {
                string result = s.substr(0, i) + s.substr(i+4);
                candidates.insert(result);
            }
        }
    }
    
    if (candidates.empty()) {
        cout << "-" << endl;
    } else if (candidates.size() == 1) {
        cout << *candidates.begin() << endl;
    } else {
        cout << "+" << endl;
    }
    
    return 0;
}
