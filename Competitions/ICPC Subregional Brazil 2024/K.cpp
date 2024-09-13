#include "bits/stdc++.h"
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < n; i++)
 
using ll = long long;
using f64 = double;
using ii = pair<int, int>;
using ull = unsigned long long;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using lolo = pair<ll, ll>;
 
const string ENDL = "\n";
 
const int MAXN = 1e2, MAXM = 1e2;
 
bool dp[MAXN+10][MAXM*MAXM + 10];
 
void solve()
{
	int n; cin >> n;
	vi a(n); forn(i, n) cin >> a[i];
 
	int ans = 0;
	forn(i,n) ans+=a[i];
	
	if(ans % 2) {
		cout << "-1\n";
		return;
	}
 
	int goal = ans/2;
	memset(dp, false, sizeof dp);
	dp[0][0] = true;
 
	for (int i = 1; i <= n; i++) {
		for(int j = 0; j <= goal; j++) {
			dp[i][j] = dp[i-1][j];
 
			if (j >= a[i-1]) {
				dp[i][j] = dp[i][j] || dp[i-1][j - a[i-1]];
			}
		}
	}
 
	if (!dp[n][goal]) {
		cout << "-1\n";
		return;
	}
 
	deque<int> va, vb;
	for (int i = n; i > 0; i--) {
		if (dp[i-1][goal]) {
			vb.push_back(a[i-1]);
		}
		else {
			va.push_back(a[i-1]);
			goal -= a[i-1];
		}
	}
 
	int A = 0, B = 0;
	vi res;
	while (!va.empty() || !vb.empty()) {
		if (A <= B) {
			A += va.front();
			cout << va.front();
			va.pop_front();
		}
		else {
			B += vb.front();
			cout << vb.front();
			vb.pop_front();
		}
		cout << " \n"[va.empty() && vb.empty()];
	}
}
 
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--) solve();
 	return 0;
}
