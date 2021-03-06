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
const int N = 2004;
const int modn = 1000000007;

int n, m;
int to[N*N], nx[N*N], head[N], vis[N];
int low[N], d[N], st[N], instac[N], comp[N];
int ps, g, tempo, es;

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
        } else if (instac[v]) low[u] = min(low[u], d[v]);
    }
    if(low[u] == d[u]) {
        int v;
        do {
            v = st[--ps];
            instac[v] = 0;
            comp[v] = g;
        } while(u != v);
        g++;
    }
}

int main() {
    while(scanf("%d %d",&n,&m) && n) {
        memset(vis,0,sizeof vis);
        memset(head,0,sizeof head);
        es = 2;
        tempo = 0;
        g = 0;
        for(int i = 0; i < m; i++) {
            int u,v,p;
            scanf("%d %d %d",&u,&v,&p);
            u--; v--;
            to[es] = v; nx[es] = head[u]; head[u] = es++;
            if(p == 2) {
                to[es] = u; nx[es] = head[v]; head[v] = es++;
            }
        }
        for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);
        printf("%d\n",g==1);
    }
}

