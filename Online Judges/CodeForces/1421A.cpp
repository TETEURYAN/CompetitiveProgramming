#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include "ilcplex/cplex.h"
 
using namespace std;
const int N1 = (int)2e5 + 100;
#define DEBUG false
#define db(x)  \
    if (DEBUG) \
    cout << #x << ": " << x << endl
#define PI 3.14159265358979323846264338327
#define forn for (int i = 0; i < n; i++)
#define forj for (int j = 0; j < n; j++)
#define fornn for (int i = 1; i <= n; i++)
#define fornj for (int j = 1; j <= n; j++)
#define each(i, c) for (__typeof((c).begin()) i = (c).begin(), i##_end = (c).end(); i != i##_end; ++i)
#define all(x) (x).begin(), (x).end()
#define inverse(x) sort(x.rbegin(), x.rend());
#define sz(arr) (int)(arr.size())
#define lower(x)      \
    for (auto &i : x) \
        i = tolower(i, locale());
#define mem(arr, b) memset((arr), (b), sizeof(arr))
#define f first
#define s second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define yes cout << "Yes" << '\n';
#define no cout << "No" << '\n';
#define one cout << -1 << '\n';
#define int long long
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef set<ll> si;
typedef set<char> sc;
typedef vector<ll> vi;
typedef priority_queue<ll> pri;
typedef vector<char> vc;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
const long long M = 1e9 + 7;
#define N 10000005
#define lli unsigned long long int
#define ll long long
#define nl endl;
 
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
ll sqrt(ll arr)
{
    ll l = 0;
    ll r = arr;
    ll ans = 0;
    while (l <= r)
    {
        ll mid = l + ((r - l) / 2);
        if (mid * mid <= arr)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
vi factorization(ll n)
{
    vi v;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (i * i != n)
            {
                v.push_back(n / i);
            }
        }
    }
    return v;
}
ll moduloMultiplication(ll arr, ll b)
{
    ll res = 0;
    arr %= M;
    while (b)
    {
        if (b & 1)
            res = (res + arr) % M;
        b >>= 1;
    }
    return res;
}
ll powermod(ll x, ll y, int mod = M)
{
    ll res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
int countDigits(ll n)
{
    int k = 0;
    while (n > 0)
    {
        n = n / 10;
        k++;
    }
    return k;
}
ll countPrimes(ll n)
{
    vector<bool> ans(n + 1, 1);
    ans[0] = ans[1] = 0;
    ll prime = 0;
    for (ll i = 2; i < n; ++i)
    {
        if (ans[i])
        {
            prime++;
            for (ll j = 2 * i; j < n; j += i)
            {
                ans[j] = 0;
            }
        }
    }
    return prime;
}
ll findMex(vector<ll> arr)
{
    sort(arr.begin(), arr.end());
    ll mex = 0;
    for (ll i = 0; i < static_cast<ll>(arr.size()); i++)
    {
        if (arr[i] == mex)
        {
            mex++;
        }
    }
    return mex;
}
void displayMatrix(vector<vector<ll>> &mat)
{
    for (auto v : mat)
    {
        for (auto e : v)
            cout << e << " ";
        cout << "\n";
    }
}

vi seg;

int single(int x)
{
  return x;
}

int neutral()
{
  return 0;
}

    int merge(int a, int b)
{
  return a + b;
}

void update(int i, int l, int r, int q, int x)
{
  if (l == r)
  {
    seg[i] = single(x);
    return;
  }
  int mid = (l + r) >> 1;
  if (q <= mid)
    update(i << 1, l, mid, q, x);
  else
    update((i << 1) | 1, mid + 1, r, q, x);
  seg[i] = merge(seg[i << 1], seg[(i << 1) | 1]);
}

int query(int l, int r, int ql, int qr, int i)
{
  int mid = (l + r) >> 1;
  if (l > r || l > qr || r < ql)
    return neutral();
  if (l >= ql && r <= qr)
    return seg[i];
  return merge(query(l, mid, ql, qr, i << 1), query(mid + 1, r, ql, qr, (i << 1) | 1));
}

void build(int l, int r, int i, vi ar)
{
  if (l == r)
  {
    seg[i] = single(ar[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, i << 1,ar);
  build(mid + 1, r, (i << 1) | 1, ar);
  seg[i] = merge(seg[i << 1], seg[(i << 1) | 1]);
}
 
string sim = "yes";
string nao = "nao";
string norte = "Norte";
string sul = "Sul";
string leste = "Leste";
string oeste = "Oeste";
 
const int INF = INT_MAX;
const int undef = 1 << 28;

auto comp = [](pair<ll, ll> a, pair
        <ll,ll> b) {
return a.second > b.second;
};


ll bts(ll x) {
    if (x == 0) return 0; // Nenhum bit setado
    int msb = 31 - __builtin_clz(x);  // Most significant bit (0-based)
    int lsb = __builtin_ctz(x);       // Least significant bit (0-based)
    return msb - lsb + 1;
}

void solve(){
    ll a,b;
    cin >>a >> b;


    ll value = a & b;
    

    cout << (a^value) + (b^value) << nl

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){
        solve();
    }
    // solve();

    // return 0;
}

 
/*⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣤⣶⣤⣤⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⡿⠋⠉⠛⠛⠛⠿⣿⠿⠿⢿⣇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⡀⢀⣽⣷⣆⡀⠙⣧⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣷⠶⠋⠀⠀⣠⣤⣤⣉⣉⣿⠙⣿⠀⢸⡆⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⠁⠀⠀⠴⡟⣻⣿⣿⣿⣿⣿⣶⣿⣦⡀⣇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢨⠟⡿⠻⣿⠃⠀⠀⠀⠻⢿⣿⣿⣿⣿⣿⠏⢹⣿⣿⣿⢿⡇⠀⠀
⠀⠀⠀⠀⠀⠀⣿⣼⣷⡶⣿⣄⠀⠀⠀⠀⠀⢉⣿⣿⣿⡿⠀⠸⣿⣿⡿⣷⠃⠀⠀
⠀⠀⠀⠀⠀⠀⢻⡿⣦⢀⣿⣿⣄⡀⣀⣰⠾⠛⣻⣿⣿⣟⣲⡀⢸⡿⡟⠹⡆⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢰⠞⣾⣿⡛⣿⣿⣿⣿⣰⣾⣿⣿⣿⣿⣿⣿⣿⣿⡇⢰⡇⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠘⠀⣿⡽⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⠿⣍⣿⣧⡏⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣷⣮⣽⣿⣷⣙⣿⡟⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣹⡿⠇⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡧⣦⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢠⡆⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣾⣿⣿⣿⣿⣿⣿⡶⠏⠀⠀⠀⠀
⣀⣠⣤⡴⠞⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠚⣿⣿⣿⠿⣿⣿⠿⠟⠁⠀⠀⠀⠀⠀
⠉⠀⢀⡴⠂⠀⠀⠀⠀⠀⠀⠀⠀⢠⠀⠀⢀⣿⣿⠁⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣠⣴⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠀⠀⣾⣿⠋⠀⢠⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣆⣼⣿⠁⢠⠃⠈⠓⠦⣄⡀⠀⠀⠀⠀⠀⠀
⠻⠿⢷⣦⣤⣤⣤⣦⣄⣀⣀⠀⢀⣿⣿⠻⣿⣰⠻⠀⠸⣧⡀⠀⠉⠳⣄⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠉⠉⠙⠛⠿⣦⣼⡏⢻⣿⣿⠇⠀⠁⠀⠻⣿⠙⣶⣄⠈⠳⣄⡀⠀
⠀⠀⠀⠀⠀⠀⠀⠁⣐⠀⠀⠀⠈⠳⡘⣿⡟⣀⡠⠿⠶⠒⠟⠓⠀⠹⡄⢴⣬⣍⡁
⠀⠀⠀⠀⠀⠀⠀⠀⠙⢀⣀⠐⠲⠤⠁⢘⣠⣿⣷⣦⠀⠀⠀⠀⠀⠀⠙⢿⣿⣏⠁
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠈⣿⣿⣷⣯⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⠆
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢦⠀⢹⣿⣏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⣸⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⡟⢬⣿⣷⣤⣀⣄⣀⡀⠀⠀⠀⠀⠀⠀⠈⣿⣿⡄⣉⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/
