#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
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
#define nl '\n';
 
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
typedef vector<vb> vis;
const long long M = 1e9 + 7;
#define N 10000005
#define lli unsigned long long int
#define ll long long
 
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0  or  n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0  or  n % (i + 2) == 0)
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
 
string sim = "yes";
string nao = "nao";
string norte = "Norte";
string sul = "Sul";
string leste = "Leste";
string oeste = "Oeste";
 
 
const int INF = INT_MAX;
const int undef = 1 << 28;

const ll dx[] = {-1,1,0,0};
const ll dy[] = {0,0,-1,1};

const char dir[] = {'U', 'D','L', 'R'};


bool is_valid(ll x, ll y, ll n , ll m){
    return x >= 0 and x < n and y>= 0 and y < m;
}

ll tamm(ll a){
    ll tam = 0;
    ll ans = a;
    while(tam < a){
        ans /= 10;
        tam++;
    }

    return tam;
}

void solve() {
    ll n,m,s;

    cin >> n;
    vi a(n);
    vi b(n);
    
    m = 0, s = 0;

    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    m+=a[n-1];
    
    for(int i = 0; i < n-1; i++){
      if(a[i]>b[i+1]){
        m+=a[i];
        s+=b[i+1];
      }
    }
    cout << m-s << endl;
}


signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin.tie(0)->sync_with_stdio(0);
    
    ll t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
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