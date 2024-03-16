/*
 Guloso que pega o maior e o menor e realiza a operação 2*(maior+maior2) - 2*(menor + menor2)
  */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
const int N1 = (int)2e5 + 100;
#define PI 3.14159265358979323846264338327
#define forn for(i=0;i<n;i++)
#define fornn for(i=1;i<=n;i++)
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define yes cout<<"YES"<<'\n';
#define no  cout<<"NO"<<'\n';
#define one  cout<<-1<<'\n';
#define nl  '\n';
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef set<ll> si;
typedef set<char> sc;
typedef vector<ll> vi;
typedef priority_queue<ll> pri;
typedef vector<char> vc;
typedef pair<ll,ll> pi;
typedef vector<pi>	vpi;
typedef vector<vi>	vvi;
typedef vector<vc>	vvc;
typedef vector<string> vs;
const long long M = 1e9+7;
#define N  10000005
#define lli unsigned long long int
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	lli t;
	cin >> t;
	while(t--){
		lli n, i = 0;
		cin >> n;
		vi arr(n);
		forn cin >> arr[i];
 
		sort(all(arr));
 
		lli ans = 2*(arr[n-1] + arr[n-2]) - 2*(arr[0] + arr[1]);
		cout << ans << nl;
 
	}
 
    return 0;
}
