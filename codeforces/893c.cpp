#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;

vector<int> adj[N];
int n, m, vis[N], p[N];
ll c[N];

void dfs(int u) {
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v]) 
            dfs(v);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i= 0; i < n; i++)  {
        scanf("%lld", c+i);
        p[i] = i;
    }
    sort(p, p+n, [&](int i, int j) { return c[i] < c[j]; });
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll ans = 0;
    for(int u = 0; u < n; u++) if(!vis[p[u]]) { ans += c[p[u]]; dfs(p[u]); }
    printf("%lld\n", ans);
}

