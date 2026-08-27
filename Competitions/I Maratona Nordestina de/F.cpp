#include <bits/stdc++.h>
using namespace std;


typedef double ld;
const ld eps = 1e-9;

bool eq(ld a, ld b) {
    return abs(a - b) <= eps;
}

struct pt { // ponto
    ld x, y;
    pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
    pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    pt operator * (const ld c) const { return pt(x*c, y*c); }
    pt operator / (const ld c) const { return pt(x/c, y/c); }
    ld operator * (const pt p) const { return x*p.x + y*p.y; } // produto escalar
    ld operator ^ (const pt p) const { return x*p.y - y*p.x; } // produto vetorial
    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
    }
};

ld dist(pt p, pt q) { // distancia entre dois pontos
    return hypot(p.x - q.x, p.y - q.y);
}


struct circ { // circulo (sombra do guarda-sol)
    pt c;
    ld r;
    circ(pt c_ = pt(), ld r_ = 0) : c(c_), r(r_) {}
    friend istream& operator >> (istream& in, circ& o) {
        return in >> o.c >> o.r;
    }
};

ld distMar(circ a) {
    return max(0.0, a.c.y - a.r);
}

ld distCalcadao(circ a, ld H) {
    return max(0.0, (H - a.c.y) - a.r);
}

ld distCirc(circ a, circ b) {
    return max(0.0, dist(a.c, b.c) - a.r - b.r);
}

signed main() {
    int n;
    ld H;
    cin >> n >> H;

    vector<circ> umbrellas(n);
    for (auto &o : umbrellas) cin >> o;

    int S = 0, T = n + 1;
    int V = n + 2;

    vector<vector<ld>> w(V, vector<ld>(V, 0.0));

    for (int i = 0; i < n; i++) {
        int u = i + 1;
        w[S][u] = w[u][S] = distMar(umbrellas[i]);
        w[u][T] = w[T][u] = distCalcadao(umbrellas[i], H);
        for (int j = i + 1; j < n; j++) {
            int v = j + 1;
            w[u][v] = w[v][u] = distCirc(umbrellas[i], umbrellas[j]);
        }
    }
    w[S][T] = w[T][S] = H;

    vector<ld> d(V, DBL_MAX);
    vector<bool> vis(V, false);
    d[S] = 0.0;

    for (int it = 0; it < V; it++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!vis[i] && (u == -1 || d[i] < d[u])) u = i;
        }
        if (d[u] == DBL_MAX) break;
        vis[u] = true;
        for (int v = 0; v < V; v++) {
            if (d[u] + w[u][v] < d[v]) d[v] = d[u] + w[u][v];
        }
    }

    cout << fixed << setprecision(10) << d[T] << "\n";

    return 0;
}
