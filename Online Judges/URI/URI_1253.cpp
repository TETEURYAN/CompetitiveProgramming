#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		string s;
		int d;
		cin >> s >> d;

		for(int i = 0; i < s.size(); i++)
			s[i] = ((s[i]-'A'-d + 26)%26) + 'A';
		cout << s << endl;
	}

    return 0;
}
