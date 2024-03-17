     
   /*
The answer is 1
in the following cases:
If smod3=2then we can add 1 to any element to make the sum divisible by 3
If there exists an aisuch that smod3=aimod3, then we can remove such ai to make the sum divisible by 3 
Otherwise, if smod3=1
, we cannot achieve the required sum in one operation. We can increase any element twice, then the sum will increase by 2 and become divisible by 3.
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
        int t;
        cin>>t;
     
        while(t--){
            int a;
            cin>>a;
     
            int sum=0;
            bool mod=false;
            for(int i=0;i<a;i++){
                int x;
                cin>>x;
     
                sum+=x;
    	    	if(x%3==1)mod=true;
            }
            if(sum%3==0) cout<<0<<endl;
            else if(sum%3==2) cout<<1<<endl;
            else{
                if(mod==true)cout<<1<<endl;
                else cout<<2<<endl;
            }
        }
    }
