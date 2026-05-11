#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<string> blocos;
    int cnt = 0;
    string cur = "";

    for (char c : s) {
        cur += c;
        if (c == '(') cnt++;
        else cnt--;
        if (cnt == 0) {
            blocos.push_back(cur);
            cur = "";
        }
    }

    bool equal = true;
    for (int i = 1; i < (int)blocos.size(); i++) {
        if (blocos[i] != blocos[0]) {
            equal = false;
            break;
        }
    }

    if (equal) {
        cout << "no\n";
    } else {
        string s = "";
        for (int i = 1; i < (int)blocos.size(); i++)
            s += blocos[i];
        s += blocos[0];
        cout << s << "\n";
    }

    return 0;
}
