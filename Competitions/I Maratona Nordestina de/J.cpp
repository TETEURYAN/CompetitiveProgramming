#include <bits/stdc++.h>
using namespace std;

#define int long long int 

// Segment tree básica: soma em intervalo + update pontual.
// tree[node] guarda a soma do intervalo [l, r] representado por node.
struct SegTree {
    int n;
    vector<pair<int,int>> tree;

    SegTree(int n) : n(n), tree(4 * n) {}

    void build(vector<long long> &a, int node, int l, int r) {
        if (l == r) {
            tree[node] = make_pair(a[l],l);
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * node, l, mid);
        build(a, 2 * node + 1, mid + 1, r);
        tree[node] = max(tree[2 * node],tree[2 * node + 1]);
    }

    // soma de a[ql..qr]
    pair<int,int> query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return {-1,-1}; // fora do intervalo
        if (ql <= l && r <= qr) return tree[node]; // totalmente dentro
        int mid = (l + r) / 2;
        return max(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
    }
};

signed main() {
    
    int n,q;

    cin >> n >> q;
    vector<int> arr(n);
    vector<pair<int,int>> query(q);


    for(auto & i : arr) cin >> i;
    for(auto & [a,b] : query) cin >> a >> b;

    SegTree st(n);
    st.build(arr, 1, 0, n - 1);

    vector<string> ans;

    for(auto [a,b] : query){
      a--,b--;
      auto [maxv,pos] = st.query(1,0,n-1,a,b);
      
      if(pos == a or pos == b) ans.push_back("Adilson");
      else if((a+b) & 1) ans.push_back("Adilson");
      else ans.push_back("Reginaldo");

    }

    for(auto i : ans) cout << i << endl;



    return 0;
}
