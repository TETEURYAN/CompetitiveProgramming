#include <iostream>
#include <vector>
#include <ciso646>
#include <limits.h>
#include <algorithm>

using namespace std;

struct info {
    long int peek, end, number;
};

vector<info> monster;

int search(int value) {
    int peek = 0, last = (int)monster.size() - 1;
    while(peek <= last) {
        int m = (peek + last) / 2;
        if (monster[m].peek <= value and value <= monster[m].end) return monster[m].number;
        else if (value < monster[m].peek) last = m - 1;
        else peek = m + 1;
    }
    return 0;
}

int main() {
    int n, p, ans;
    cin >> n >> p;
	monster.assign(n, {0, INT_MAX, 0});
    for (int i = 0; i < n-1; i++) {
        cin >> monster[i].end, monster[i].end--;
        if(i) monster[i].peek = monster[i - 1].end + 1;
    }

    monster[n - 1].peek = monster[n - 2].end + 1;

	int i = 0;
	while(i < n)
        cin >> monster[i].number, i++;
    
	i = 0;
    while(i < p) {
        cin >> ans;
        if(i) cout << " ";
        cout << search(ans);
		i++;
    }
    cout << endl;
    return 0;  
}