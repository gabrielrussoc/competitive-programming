#include <vector>
#include <algorithm>
#include <cstdio>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1e5+7, M = 2e5+7;
const int K = 22;

int n, m;
int l[N][K], dep[N], mark[N], cov[N];
int head[N], to[M], nx[M], es = 2;

void add_edge(int u, int v) {
    to[es] = v; nx[es] = head[u]; head[u] = es++;
    to[es] = u; nx[es] = head[v]; head[v] = es++;
}

void dfs(int u, int p, int d) {
    l[u][0] = p; dep[u] = d;
    for(int i = 1; i < K; i++)
        l[u][i] = l[l[u][i-1]][i-1];
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(v != p) dfs(v, u, d+1);
    }
}

void count(int u, int p) {
    cov[u] = mark[u];
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(v != p) {
            count(v, u);
            cov[u] += cov[v]; 
        }
    }
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    if(dep[u] < dep[v]) {
        for (int i = K-1; i >= 0; i--)
            if(dep[l[v][i]] >= dep[u])
                v = l[v][i];
    }
    if(u == v) return v;
    for(int i = K-1; i >= 0; i--)
        if(l[v][i] != l[u][i])
           v = l[v][i], u = l[u][i];
   return l[v][0];
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        add_edge(u, v);
    }
    dfs(0, 0, 0);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        int w = lca(u,v);
        mark[u]++;
        mark[v]++;
        mark[w] -= 2;
    }
    count(0, 0);
    ll ans = 0;
    for(int u = 1; u < n; u++) {
        if(cov[u] == 0) ans += ll(m);
        else if(cov[u] == 1) ans++;
    }
    printf("%lld\n", ans);
}

