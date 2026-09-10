#include <bits/stdc++.h>
using namespace std;

#define int long long

struct SegTree {
    int n;
    vector<int> tree;
    vector<int> lazy;

    SegTree(int n) : n(n) {
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
    }

    void build(vector<int>& a, int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(a, 2 * node, l, mid);
        build(a, 2 * node + 1, mid + 1, r);

        tree[node] = max(tree[2 * node],
                         tree[2 * node + 1]);
    }

    void push(int node) {
        if (lazy[node] == 0)
            return;

        tree[2 * node] += lazy[node];
        tree[2 * node + 1] += lazy[node];

        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];

        lazy[node] = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, int value) {

        // Fora do intervalo
        if (qr < l || r < ql)
            return;

        // Intervalo completamente dentro
        if (ql <= l && r <= qr) {
            tree[node] += value;
            lazy[node] += value;
            return;
        }

        push(node);

        int mid = (l + r) / 2;

        update(2 * node, l, mid,
               ql, qr, value);

        update(2 * node + 1, mid + 1, r,
               ql, qr, value);

        tree[node] = max(tree[2 * node],
                         tree[2 * node + 1]);
    }

    int query(int node, int l, int r,
              int ql, int qr) {

        // Fora do intervalo
        if (qr < l || r < ql)
            return LLONG_MIN;

        // Intervalo completamente dentro
        if (ql <= l && r <= qr)
            return tree[node];

        push(node);

        int mid = (l + r) / 2;

        int left = query(2 * node, l, mid,
                         ql, qr);

        int right = query(2 * node + 1,
                          mid + 1, r,
                          ql, qr);

        return max(left, right);
    }
};
Como usar

Se o vetor for indexado de 0 até n - 1:

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegTree st(n);

    // Construir a árvore
    st.build(a, 1, 0, n - 1);

    // Somar 5 em todos os elementos de [2, 6]
    st.update(1, 0, n - 1, 2, 6, 5);

    // Máximo no intervalo [1, 7]
    cout << st.query(1, 0, n - 1, 1, 7) << '\n';

    return 0;
}
