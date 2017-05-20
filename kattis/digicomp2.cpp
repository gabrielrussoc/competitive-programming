#include <bits/stdc++.h>
#define pb push_back
#define left carpincho
using namespace std;
typedef long long ll;

const int M = 500005;

int m;
ll n;
int adj[M][2], left[M], topo[M], pos[M], vis[M], tim;
ll ans[M];

void dfs(int u) {
    vis[u] = 1;
    for(int i = 0; i < 2; i++) {
        int v = adj[u][i];
        if(!vis[v]) dfs(v);
    }
    pos[u] = tim++;
}

void get_topo() {
    dfs(1);
    for(int i = 0; i < m; i++) topo[i] = i+1;
    sort(topo, topo+m, [](int i, int j) { return pos[i] > pos[j]; });
}

int main() {
    scanf("%lld %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int l, r;
        char c;
        scanf(" %c %d %d", &c, &l, &r);
        adj[i][0] = l;
        adj[i][1] = r;
        left[i] = (c == 'L');
    }
    get_topo();
    ans[1] = n;
    for(int i = 0; i < m; i++) {
        int u = topo[i];
        int f = adj[u][0];
        int s = adj[u][1];
        if(!left[u]) swap(f, s);
        ans[f] += (ans[u] + 1ll)/2ll;
        ans[s] += ans[u]/2ll;
    }
    for(int u = 1; u <= m; u++) putchar(left[u]^(ans[u]&1) ? 'L' : 'R');
}

