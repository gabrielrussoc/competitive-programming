#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

struct edge {
    int v;
    ll w;
    edge(){}
    edge(int _v, ll _w):v(_v), w(_w) {}
};

const int N = 10004;
ll e[N];
int n;
ll c, ans;
vector<edge> adj[N];

void dfs(int u, int p = -1) {
    for(edge &ed : adj[u]) {
        int v = ed.v;
        if(v == p) continue;
        dfs(v, u);
        ll w = ed.w;
        ans += 2 * w * ((e[v]+c-1)/c);
        e[u] += e[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> e[i];
    for(int i = 0; i < n-1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w; u--; v--;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dfs(0);
    cout << ans << endl;
}

