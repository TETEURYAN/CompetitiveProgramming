    #include <bits/stdc++.h>
    using namespace std;
     
    #define int long long int
     
    template<typename T>
    ostream& operator<<(ostream& out, const vector<T> &vec) {
        for(const auto &i : vec){
            out << i << " ";
        }
        return out;
    }
     
    void build(int n, vector<int> &tree, vector<int> &a) {
        int size = 1 << n;
        for (int i = 0; i < size; i++) {
            tree[size + i] = a[i];
        }
     
        for (int i = size - 1; i > 0; i--) {
            int level = (n - 1) - (31 - __builtin_clz(i));
            if (level % 2 == 0) {
                tree[i] = tree[2 * i] | tree[2 * i + 1];
            } else {
                tree[i] = tree[2 * i] ^ tree[2 * i + 1];
            }
        }
    }
     
    void update(int index, int value, int n, vector<int> &tree) {
        int size = 1 << n;
        int pos = size + index;
        tree[pos] = value;
     
        while (pos > 1) {
            pos /= 2;
            int level = (n - 1) - (31 - __builtin_clz(pos));
            if (level % 2 == 0) {
                tree[pos] = tree[2 * pos] | tree[2 * pos + 1];
            } else {
                tree[pos] = tree[2 * pos] ^ tree[2 * pos + 1];
            }
        }
     
        cout << tree[1] << endl;
    }
     
    signed main() {
        int n, q;
        cin >> n >> q;
        int size = 1 << n;
        vector<int> a(size), tree(2 * size);
        for (int i = 0; i < size; i++) cin >> a[i];
        build(n, tree, a);
     
        for (int i = 0; i < q; i++) {
            int p, b;
            cin >> p >> b;
            update(p - 1, b, n, tree);
        }
     
        return 0;
    }

