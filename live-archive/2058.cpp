#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 29;

struct edge {
    int u, v, w;
    edge() {}
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
} e[2*N*N];

int r[N], t[N], d[N], m, s = 24, n;
int inf = 12345678;

void build(int k) {
    m = 0;
    e[m++] = edge(s, 0, t[0]);
    for(int i = 1; i < 24; i++) e[m++] = edge(i-1, i, t[i]);
    for(int i = 0; i < 8; i++) e[m++] = edge(i, 16+i, k-r[i]);
    for(int i = 8; i < 24; i++) e[m++] = edge(i, i-8, -r[i]);
    e[m++] = edge(s, 23, k);
    e[m++] = edge(23, s, -k);
}

bool bellman(int k) {
    build(k);
    for(int i = 0; i < 24; i++) d[i] = inf;
    d[s] = 0;
    for(int i = 0; i < 24; i++) {
        for(int j = 0; j < m; j++) {
            int u = e[j].u, v = e[j].v, w = e[j].w;
            d[v] = min(d[v], d[u] + w);
        }
    }
    for(int i = 0; i < m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(d[v] > d[u] + w) return false;
    }
    return true;
}

int solve() {
    int lo = 0, hi = n+1;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(bellman(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        for(int i = 0; i < 24; i++) {
            scanf("%d", r+i);
            t[i] = 0;
        }
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            t[x]++;
        }
        int ans = solve();
        if(ans == n+1) puts("No Solution");
        else printf("%d\n", ans);
    }
}

