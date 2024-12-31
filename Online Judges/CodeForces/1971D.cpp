#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    string binaryString;
    cin >> binaryString;

    int count_zero = 0, count_one = 0, total = 1;
    char current = binaryString[0];
    bool pivot = false;

    for (int i = 1; i < binaryString.size(); i++) {
        if (current == '0' && binaryString[i] == '1') {
            pivot = true;
        }

        if (current == '0' && binaryString[i] == '1') {
            count_zero++;
            current = '1';
        }
        
        if (current == '1' && binaryString[i] == '0') {
            count_one++;
            current = '0';
        }

    }
    
    total += count_zero + count_one;

    if (pivot) {
        total--;
    }

    cout << (total == 0 ? 1 : total) << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}
