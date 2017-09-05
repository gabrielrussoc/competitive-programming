#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 200005;
int n, a[N], ans[N];
vector<int> adj[N];

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

struct state {
    int u, g, f;
    state() {}
    state(int u, int g, int f) : u(u), g(g), f(f) {}
    bool operator<(const state &o) const {
        if(u != o.u) return u < o.u;
        if(g != o.g) return g < o.g;
        return f < o.f;
    }
};
map<state, bool> vis;

void dfs(int u, int g, int f, int p) {
    state s = state(u, g, f);
    if(vis[s]) return;
    vis[s] = true;
    ans[u] = max(ans[u], gcd(g, a[u]));
    if(!f) ans[u] = max(ans[u], g);
    for(int v : adj[u]) {
        if(v == p) continue;
        if(!f) dfs(v, g, 1, u);
        dfs(v, gcd(g, a[u]), f, u);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a+i);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, 0, 0, -1);
    for(int u = 0; u < n; u++) printf("%d%c", ans[u], " \n"[u == n-1]);
}

