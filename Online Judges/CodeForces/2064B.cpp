#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
#define endl '\n'
#define MAXB 60
#define PI acos(-1)
#define pp pop_back
#define pb push_back
#define mkp make_pair
#define MAXN 200200
#define mod 1000000007
#define int long long int
#define pi pair<int, int>
#define pii pair<pi, int>
#define maior(x, y, z) *max_element(x.begin() + y, x.begin() + z)
#define menor(x, y, z) *min_element(x.begin() + y, x.begin() + z)

template<typename T>
using matriz = vector<vector<T>>;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int &i : a) cin >> i;
        
        vector<int> mp(n + 1, 0LL);
        for(int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
        vector<bool> un(n, false);
        for(int i = 0; i < n; i++) {
            if(mp[a[i]] == 1) {
                un[i] = true;
            }
        }

        int bl = 0, l = -1, r = -1, cl = -1, csz = 0;
        for(int i = 0; i < n; i++) {
            if(un[i]) {
                if(cl == -1) {
                    cl = i;
                    csz = 1;
                } else {
                    csz++;
                }
            } else {
                if(csz > bl) {
                    bl = csz;
                    l = cl;
                    r = i - 1;
                }
                cl = -1;
                csz = 0;
            }
        }

        if(csz > bl) {
            bl = csz;
            l = cl;
            r = n - 1;
        }

        if(bl == 0) cout << 0 << endl;
        else cout << (l + 1) << " " << (r + 1) << endl; 
    }
}

//diolinux
