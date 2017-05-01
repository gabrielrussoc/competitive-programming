#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 105;
int n, q;
int e[N], s[N], w[N][N];

struct vertex {
    int u, horse, left;
    vertex(int u, int horse, int left) : u(u), horse(horse), left(left) {}
    bool operator < (const vertex &o) const {
        if(u != o.u) return u < o.u;
        if(horse != o.horse) return horse < o.horse;
        return left < o.left;
    }
};

map<vertex, double> d;
map<vertex, bool> vis;
typedef pair<double, vertex> pdv;

double ans(int from, int to) {
    d.clear();
    vis.clear();
    priority_queue<pdv> pq;
    vertex f = vertex(from, from, e[from]);
    d[f] = 0;
    pq.push(pdv(-d[f], f));
    while(!pq.empty()) {
        vertex u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int _v = 0; _v < n; _v++) {
            vertex v1 = vertex(_v, u.horse, u.left - w[u.u][_v]);
            vertex v2 = vertex(_v, u.u, e[u.u] - w[u.u][_v]);
            bool gv1 = false, gv2 = false;
            if(w[u.u][v1.u] != -1 && v1.left >= 0) {
                double wei = w[u.u][v1.u];
                double spd = s[v1.horse];
                double cost = wei / spd;
                if(!d.count(v1) || d[v1] > d[u] + cost) {
                    d[v1] = d[u] + cost;
                    gv1 = true;
                } 
            }
            if(w[u.u][v2.u] != -1 && v2.left >= 0) {
                double wei = w[u.u][v2.u];
                double spd = s[v2.horse];
                double cost = wei / spd;
                if(!d.count(v2) || d[v2] > d[u] + cost) {
                    d[v2] = d[u] + cost;
                    gv2 = true;
                }
            } 
            if(gv1 && gv2) {
                if(d[v1] < d[v2]) pq.push(pdv(-d[v1], v1));
                else pq.push(pdv(-d[v2], v2));
            } else if(gv1) {
                pq.push(pdv(-d[v1], v1));
            } else if(gv2) {
                pq.push(pdv(-d[v2], v2));
            }
        }
    }
    double ans = 1 / 0.;
    for(auto v : d) {
        if(v.first.u == to) ans = min(ans, v.second);
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++) {
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++)
            scanf("%d %d", e+i, s+i);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &w[i][j]);
        fprintf(stderr, "Case %d\n", tc);
        fflush(stderr);
        printf("Case #%d:", tc);
        for(int i = 0; i < q; i++) {
            int u, v;
            scanf("%d %d", &u, &v); u--; v--;       
            printf(" %.20lf", ans(u, v));
        }
        putchar('\n');
    }
}

