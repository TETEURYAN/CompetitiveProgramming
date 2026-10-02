#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    bool operator<(const pt& o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
    bool operator==(const pt& o) const {
        return x == o.x && y == o.y;
    }
    pt operator-(const pt& o) const { return pt(x - o.x, y - o.y); }
};

ll cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }

// > 0 se a->b->c faz curva anti-horaria, 0 se colinear, < 0 se horaria
ll ccw(pt a, pt b, pt c) { return cross(b - a, c - a); }

// retorna o fecho convexo em ordem anti-horaria, sem pontos colineares
// o(n log n)
vector<pt> convex_hull(vector<pt> p) {
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size();
    if (n <= 2) return p;

    vector<pt> h(2 * n);
    int k = 0;

    // hull inferior
    for (int i = 0; i < n; i++) {
        while (k >= 2 && ccw(h[k - 2], h[k - 1], p[i]) <= 0) k--;
        h[k++] = p[i];
    }
    // hull superior
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && ccw(h[k - 2], h[k - 1], p[i]) <= 0) k--;
        h[k++] = p[i];
    }

    h.resize(k - 1);
    return h;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pt> p(n);
    for (auto& q : p) scanf("%lld %lld", &q.x, &q.y);

    vector<pt> h = convex_hull(p);
    printf("%d\n", (int)h.size());
    for (auto& q : h) printf("%lld %lld\n", q.x, q.y);
    return 0;
}
