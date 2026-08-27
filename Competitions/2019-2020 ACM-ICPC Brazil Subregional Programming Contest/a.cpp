#include <bits/stdc++.h>
using namespace std;

typedef double ld;
const ld eps = 1e-9;
const ld INF = 1e18;

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

struct circ { // circulo (zona proibida do sensor)
    pt c;
    ld r;
    circ(pt c_ = pt(), ld r_ = 0) : c(c_), r(r_) {}
    friend istream& operator >> (istream& in, circ& o) {
        return in >> o.c >> o.r;
    }
};


ld distG1(circ a, ld M) {
    ld baixo = max(0.0, a.c.y - a.r);
    ld direita = max(0.0, (M - a.c.x) - a.r);
    return min(baixo, direita);
}


ld distG2(circ a, ld N) {
    ld esquerda = max(0.0, a.c.x - a.r);
    ld cima = max(0.0, (N - a.c.y) - a.r);
    return min(esquerda, cima);
}

ld distCirc(circ a, circ b) {
    return max(0.0, dist(a.c, b.c) - a.r - b.r);
}

signed main() {
    ld M, N;
    int K;
    cin >> M >> N >> K;

    vector<circ> sensores(K);
    for (auto &o : sensores) cin >> o;

    int G1 = 0, G2 = K + 1;
    int V = K + 2;

    vector<vector<ld>> w(V, vector<ld>(V, INF));

    for (int i = 0; i < K; i++) {
        int u = i + 1;
        w[G1][u] = w[u][G1] = distG1(sensores[i], M);
        w[G2][u] = w[u][G2] = distG2(sensores[i], N);
        for (int j = i + 1; j < K; j++) {
            int v = j + 1;
            w[u][v] = w[v][u] = distCirc(sensores[i], sensores[j]);
        }
    }


    vector<ld> d(V, INF);
    vector<bool> vis(V, false);
    d[G1] = 0.0;

    for (int it = 0; it < V; it++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!vis[i] && (u == -1 || d[i] < d[u])) u = i;
        }
        if (d[u] >= INF) break;
        vis[u] = true;
        for (int v = 0; v < V; v++) {
            if (d[u] + w[u][v] < d[v]) d[v] = d[u] + w[u][v];
        }
    }

    cout << (d[G2] < eps ? "N" : "S") << "\n";

    return 0;
}
