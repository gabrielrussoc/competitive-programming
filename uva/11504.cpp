#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 100004;
const int modn = 1000000007;

int t, n, m, g, es, ps, tempo;
int low[N], d[N], vis[N], head[N], to[N], nx[N];
int st[N], instac[N], comp[N], gr[N];

void dfs(int u) {
    vis[u] = 1;
    st[ps++] = u;
    instac[u] = 1;
    low[u] = d[u] = tempo++;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(!vis[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if(instac[v]) low[u] = min(low[u], d[v]);
    }
    if(low[u] == d[u]) {
        int v;
        do {
            v = st[--ps];
            instac[v] = 0;
            comp[v] = g;
        } while (u != v);
        g++;
    }
}


int main() {
    scanf("%d",&t);
    while(t--) {
        tempo = 0; g = 0; es = 2;
        scanf("%d %d",&n,&m);
        for(int i = 0; i < n; i++) vis[i] = head[i] = gr[i] = 0;
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--; v--;
            to[es] = v; nx[es] = head[u]; head[u] = es++;
        }
        for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);
        for(int u = 0; u < n; u++) {
            for(int e = head[u]; e; e = nx[e]) {
                int v = to[e];
                if(comp[u] != comp[v]) {
                    gr[comp[v]]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < g; i++) if(!gr[i]) ans++;
        printf("%d\n",ans);
    }
}

