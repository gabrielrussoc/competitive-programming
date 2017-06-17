#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
int vis[N], low[N], d[N], tempo, instac[N], st[N], ps, cs, sz[N], comp[N];
vector<int> adj[N], cdj[N];
int pos[N], ts, vist[N], top[N], ans[N], rc[N];
int n, m;

void dfs(int u) {
    vist[u] = 1;
    for(int v : cdj[u]) {
        if(!vist[v]) dfs(v);
    }
    pos[u] = ts++;
}

bool cmp(int u, int v) {
    return pos[u] > pos[v];
}

void solve() {
    for(int u = 0; u < cs; u++) {
        if(!vist[u]) dfs(u);
        top[u] = u;
    }
    sort(top, top+cs, cmp);
    for(int i = cs-1; i >= 0; i--) {
        int u = top[i];
        rc[u] = sz[u];
        int mx = 0;
        for(int v : cdj[u]) mx = max(mx, rc[v]);
        rc[u] += mx;
    }
    int mx = *max_element(rc, rc+cs);
    int cont = 0;
    for(int u = 0; u < cs; u++) {
        if(rc[u] == mx) cont += sz[u];
    }
    printf("%d %d\n", mx, cont);
}

void dscc(int u) {
    vis[u] = 1;
    low[u] = d[u] = tempo++;
    instac[u] = 1;
    st[ps++] = u;
    for(int v : adj[u]) {
        if(!vis[v]) {
            dscc(v);
            low[u] = min(low[u], low[v]);
        } else if (instac[v]) low[u] = min(low[u], d[v]);
    }
    if(low[u] == d[u]) {
        int v;
        do {
            sz[cs]++;
            v = st[--ps];
            comp[v] = cs;
            instac[v] = 0;
        } while (u != v);
        cs++;
    }
}

int main() {
    scanf("%d %d",&n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        adj[u].pb(v);
    }
    for(int u = 0; u < n; u++) {
        if(!vis[u]) dscc(u);
    }
    for(int u = 0; u < n; u++) {
        for(int v : adj[u]) {
            if(comp[u] != comp[v]) {
                cdj[comp[u]].pb(comp[v]);
            }
        }
    }
    solve();
}

