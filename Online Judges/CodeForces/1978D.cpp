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
    #define forn for(int i=0;i<n;i++)
    #define forj for(int j=0;j<n;j++)
    #define fornn for(int i=1;i<=n;i++)
    #define fornj for(int j=1;j<=n;j++)
    #define each(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
    #define all(x) (x).begin(), (x).end()
    #define sz(a) (int)(a.size())
    #define lower(x) for(auto & i : x) i = tolower(i, locale());
    #define mem(a,b) memset((a),(b),sizeof(a))
    #define f first
    #define s second
    #define pb push_back
    #define pp pop_back
    #define mp make_pair
    #define yes cout<<"Yes"<<'\n';
    #define no  cout<<"No"<<'\n';
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
    typedef vector<bool> vb;
    const long long M = 1e9+7;
    #define N  10000005
    #define lli unsigned long long int
    #define ll long long
     
    bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
    ll sqrt(ll a) { ll l = 0; ll r = a; ll ans = 0; while (l <= r) { ll mid = l + ((r - l) / 2); if (mid * mid <= a) { ans = mid; l = mid + 1; } else { r = mid - 1; } } return ans; }
    bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
    vi factorization(ll n){vi v; for (ll i=1;i*i<=n;i++){if (n%i==0){v.push_back(i);if (i*i!=n){v.push_back(n/i);}}}return v;}
    ll moduloMultiplication(ll a,ll b){ll res = 0;a %= M;while (b){if (b & 1)res = (res + a) % M;b >>= 1;}return res;}
    ll powermod(ll x, ll y, int mod = M){ll res = 1;x = x % mod;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % mod;y = y>>1;x = (x*x) % mod;}return res;}
    int countDigits(ll n){int k=0;while(n>0){ n = n/10; k++;}return k;}
    ll countPrimes(ll n){vector<bool> ans(n + 1, 1);ans[0] = ans[1] = 0;ll prime = 0;for (ll i = 2; i < n; ++i){if (ans[i]){prime++;for (ll j = 2 * i; j < n; j += i){ans[j] = 0;}}}return prime;}
    ll findMex(vector<ll>arr){sort(arr.begin(), arr.end()); ll mex = 0; for (ll i = 0; i < static_cast<ll>(arr.size()); i++){ if (arr[i] == mex){ mex++;}} return mex;}
    void displayMatrix(vector<vector<ll>> &mat) { for(auto v : mat) { for(auto e : v) cout <<  e << " "; cout <<"\n"; } }
     
    string sim = "yes";
    string nao = "nao";
    string norte = "Norte";
    string sul = "Sul";
    string leste = "Leste";
    string oeste = "Oeste";
     
    const int INF = INT_MAX;
     
     
    const int undef = 1 << 28;
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
        int t;
        cin >> t;
        while(t--){
                ll n,c;
        cin >> n >> c;
     
        vi a(n);
        for(ll i = 0; i < n; i++) cin >> a[i];
     
        a[0] += c;
        ll j = max_element(a.begin(), a.end()) - a.begin();
        
        vi ans(n, 0);
        for(ll i = j + 1; i < n; i++) ans[i] = i;
        if(j != 0) ans[0] = 1;
     
        ll soma = a[0];
        for(ll i = 1; i < j; i++){
            soma += a[i];
            if(soma >= a[j]) ans[i] = i;
            else ans[i] = i + 1;
        }
        for(auto i : ans) cout << i << " ";
        cout << endl;
        }
        
    }
     
     
    /*
    ⡴⠁⠀⠀⠳⣗⡆⠀⠀⠀⠀⠉⠳⣇⠀⢸⠇⠀⢀⡴⠚⡽⠀⠀⠘⠛⠉⠀⠀⠀⢀⣠⡤⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠈⢳⡄⠀⠀⠀⠀⠀⠀
    ⣧⠀⠀⠀⠀⠀⠀⢿⢳⣦⠀⠀⣀⡈⠳⠋⠀⠀⡾⠴⠚⠁⣠⡀⠀⠀⢠⡶⣲⠆⠙⠓⠋⠁⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠲⠖⠋⠈⠉⠓⠲⢤⣀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀
    ⠘⢦⣄⠀⠀⠀⠀⠈⠉⠁⠀⠘⠧⠏⠀⠀⢰⣿⠇⠀⣤⣿⡵⠃⠀⠀⠉⠉⠀⠀⠀⠀⡀⠀⣠⡴⠋⠑⠒⠤⠔⠚⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢦⣀⡇⠀⠀⠀⠀⠀⠀
    ⠾⠀⢸⣟⢿⣀⣀⡤⢾⡀⠀⣀⣴⡶⢦⣀⠀⠀⠀⡞⢧⣀⣀⣠⠦⣄⣀⣠⢿⠲⠦⠾⠉⠉⢻⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣠⠤⠴⠶⠾⢏⡵⢆⡼⢩⡇⠀⠀⠀⠀⠀⠀
    ⢰⠀⢸⢻⠀⠀⠀⠀⠈⠛⠋⢹⠀⢧⠀⠈⠉⠓⠚⠁⠀⠀⠀⠀⠀⠀⠹⡄⠸⡇⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⢀⡤⠖⠋⠉⠀⠀⠀⠀⢀⡴⢛⡴⠋⠀⢸⡇⠀⠀⠀⠀⠀⠀
    ⣿⠀⠘⡞⡇⠀⠀⠀⠀⠀⠀⢸⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡄⡇⠀⠀⠀⠀⠀⢸⠀⠀⠀⢀⡤⠚⠁⠀⠀⠀⠀⠀⠀⢀⡴⠋⢐⣟⣠⡤⠀⢸⠇⠀⠀⠀⠀⠀⠀
    ⠹⡄⠀⣿⣧⠀⠀⠀⠀⠀⠀⢸⡀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢙⠀⠀⠀⠀⠀⠸⣄⡴⠞⠉⠀⠀⣀⡤⠴⠚⠛⡇⠐⠛⠛⠛⣿⡿⠓⣲⠿⢻⡆⠀⠀⠀⠀⠀⠀
    ⣄⢳⡀⢸⣼⡀⠀⠀⠀⠀⠀⠈⣇⠈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠸⠀⠀⠀⢀⡴⠊⠁⠀⣠⡤⠖⠋⠁⠀⠀⠀⢀⣧⠀⠀⢀⡼⠋⣠⠞⠁⠀⢸⡇⠀⠀⢀⠀⠀⠀
    ⠙⢮⣣⠀⢧⢳⡄⠀⠀⠀⠀⠀⢻⡀⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆⢀⣤⠖⠋⠀⢀⣠⠟⠋⠀⠀⠀⠀⠀⠀⠀⠠⢿⠀⠀⠛⢢⣴⣳⠃⢀⣠⣿⡇⠀⢀⡏⡀⠀⠀
    ⠀⠈⠻⣧⡘⢆⠱⡄⠀⠀⠀⠀⠀⢣⠈⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡶⠋⠀⠀⣠⠴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⣠⠞⣽⣷⡾⡍⢀⡏⡇⠀⡼⠀⡇⠀⠀
    ⠀⠀⠀⠙⢿⣝⠲⠼⣦⣤⣀⡀⠀⠈⢳⡘⣧⠀⠀⠀⠀⠀⠀⠀⠀⣠⡴⠚⠁⠀⢀⡴⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡀⠴⠛⠉⠉⢀⣼⡵⠋⣸⣇⡼⠁⠀⡇⠀⠀
    ⠀⠀⠀⠀⠀⠉⠳⣦⣄⠈⠉⠉⠛⠳⠶⠿⠾⠷⠶⠶⠶⠒⠒⠛⠉⠁⢀⣀⡴⠚⠉⠀⠀⠀⠀⠀⢀⣠⣴⣶⣶⣶⣭⣙⠶⡄⠀⠀⠉⠓⠦⡄⠀⣼⣿⠟⠉⠉⠙⣇⠀⠀⡇⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠓⠶⣄⣀⡀⠀⠀⠀⠀⠀⢀⣀⣀⣠⠴⠚⠉⠁⠀⠀⠀⣀⣀⣤⣶⣾⣿⡿⠟⠛⠉⠉⠉⠛⠿⣦⠀⠀⠀⠀⠀⣿⠟⣸⠃⠀⡴⢇⠀⢻⡀⠀⡇⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⠟⠉⠛⠛⢛⣿⣏⣛⣉⣩⣤⣤⣤⣄⡀⠀⠀⠀⠹⠿⠟⠛⣋⣠⠤⠄⠀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢀⡇⠀⡼⢧⠘⠀⢸⢷⠀⢷⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⣄⣤⣾⣿⡿⠿⠿⠿⠿⠿⠿⠟⠋⠀⠀⠀⠀⠀⠀⡾⠉⡠⡤⣶⣿⣿⣻⡄⠈⢳⡄⠀⠀⠀⠀⠀⠀⣼⣼⠀⣸⢷⡈⡇⠀⢸⠘⣆⢸⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡟⠿⠁⠀⠀⠀⠀⠀⠀⠀⠀⣄⠀⠀⠀⠀⠀⠀⢧⠀⢰⡇⠹⣿⣿⠿⠧⠒⠉⠀⠀⠀⠀⠀⠀⣠⣿⠏⢀⡇⢸⡇⡇⠀⣾⠀⢹⣸⡆⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡄⠀⠀⣠⣤⣤⣶⣶⡾⣅⠀⠸⠷⠀⠀⠀⠀⠀⠈⠓⠛⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡿⠛⢠⣾⡅⢸⡟⢁⣼⠋⠀⠀⢯⡇⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣇⢠⡊⠀⢻⣿⣿⣿⠥⠼⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⢟⡽⠀⠀⢻⣿⣿⡃⣰⡿⠓⢤⡀⠀⠈⢧⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡅⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣮⠞⠁⠀⠀⣟⢛⣿⠾⢿⠒⠲⣄⢳⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠋⠀⠀⠀⠀⡿⠉⠀⠀⠘⡆⠀⢸⠈⣧⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⡇⠀⠀⠀⠀⢸⡏⠀⠀⠀⠀⢱⣠⠏⠀⠘⡆⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠟⠁⢸⡇⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⡸⠋⠀⡀⠀⢳⡀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠏⠀⠀⢸⡆⠀⠀⠀⠀⡟⠀⠀⠀⣠⠞⠁⣀⠴⢻⠀⠈⣇⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠴⠋⠀⠀⠀⠀⠀⡇⠀⠀⠀⣼⠃⠀⣠⠞⠁⣠⠾⠋⠀⠀⡇⠀⢸⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡤⠤⠚⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⢇⠀⢀⡴⠁⣠⠞⣁⣴⠞⠋⠀⠀⠀⠀⢿⠀⠸⡄
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠻⣄⠀⠐⣦⠤⠴⠒⠒⠚⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⣡⠞⣡⡶⢋⣥⡤⣤⡀⠀⢀⣤⣘⡆⠀⢷
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣯⠀⢹⢢⡀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠵⢛⣡⠞⠉⡾⠉⣠⣀⠀⡇⠀⡟⢰⠏⢣⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠶⠚⢻⠀⠸⡄⠱⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡼⣟⣡⡴⠋⠁⠀⠀⣇⠸⣇⣼⡇⣷⣤⢸⢘⡀⠘⠇⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠖⠉⠁⠀⠀⢰⡿⣆⠀⠻⡀⠹⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡴⠋⣠⣿⠁⠀⠀⠀⠀⠀⠙⣦⡬⠁⢰⠞⠁⣾⢸⠃⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠞⠉⠀⠀⠀⠀⠀⠀⠸⣇⠹⡄⠀⢇⠀⢹⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠋⠀⣼⠃⠸⡀⠀⠀⡀⣀⡀⠀⠷⠤⢄⠈⣧⡼⠁⡾⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠔⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡄⢳⠀⠸⡆⢸⡌⠳⢤⠤⠄⠤⠤⠤⠤⠤⠔⠋⠀⠀⠀⠀⢸⡀⠀⡇⠀⠸⡄⢶⣁⣀⣀⣀⣸⠀⠁⣠⠞⠁⠀⠀⠀⠀
    ⠀⠀⢀⡤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣄⢷⠀⠹⡄⢱⡄⠈⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣇⠀⢹⡀⠀⠙⠦⠬⠭⠭⠥⠴⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀
    */
