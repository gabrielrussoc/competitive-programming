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
const int N = 1004;
const int M = 100004;
const int modn = 1000000007;

int n, m, es, bridge, tempo;
int head[N], nx[2*M], to[2*M], uf[N], wf[N], comp[N], vis[N], vis2[N];
int instac[N], st[N], ps, cs, d[N], low[N];
vector<int> adj[N];

void dscc(int u) {
    vis[u] = 1;
    low[u] = d[u] = tempo++;
    instac[u] = 1;
    st[ps++] = u;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(!vis[v]) {
            dscc(v);
            low[u] = min(low[u], low[v]);
        } else if (instac[v]) low[u] = min(low[u], d[v]);
    }
    if(low[u] == d[u]) {
        int v;
        do {
            v = st[--ps];
            comp[v] = cs;
            instac[v] = 0;
        } while (u != v);
        cs++;
    }
}

void brid(int u, int p) {
    vis2[u] = 1;
    low[u] = d[u] = tempo++;
    int pai = 0;
    for(int v : adj[u]) {
        if(!vis2[v]) {
            brid(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > d[u]) bridge++;
        } else if (v != p || pai) low[u] = min(low[u], d[v]);
        if(v == p) pai++;
    }
}

int find (int i) {
    if(uf[i] == i) return i;
    return uf[i] = find(uf[i]);
}

int join (int i, int j) {
    i = find(i); j = find(j);
    if(i == j) return 0;
    if(wf[i] > wf[j]) swap(i,j);
    wf[j] += wf[i];
    uf[i] = j;
    return 1;
}

int main() {
    while(scanf("%d %d", &n, &m) != EOF) {
        es = 2;
        for(int i = 0; i < n; i++) {
            uf[i] = i;
            wf[i] = 1;
            comp[i] = i;
            head[i] = 0;
            vis[i] = 0;
            vis2[i] = 0;
            adj[i].clear();
        }
        int u, v, t;
        int cont = n;
        scanf("%d %d %d",&u,&v,&t);
        for(int i = 1; i < m; i++) {
            scanf("%d %d %d",&u,&v,&t);
            u--; v--;
            to[es] = v; nx[es] = head[u]; head[u] = es++;
            if(t == 2){ to[es] = u; nx[es] = head[v]; head[v] = es++;}
            cont -= join(u,v);
        }
        if(cont > 1) puts("*");
        else {
            cs = tempo = 0;
            for(int i = 0; i < n; i++) if(!vis[i]) dscc(i);
            if(cs == 1) puts("-");
            else {
                bridge = tempo = 0;
                for(int u = 0; u < n; u++) {
                    for(int e = head[u]; e; e = nx[e]) {
                        int v = to[e];
                        if(comp[u] != comp[v]){
                            adj[comp[u]].pb(comp[v]);
                            adj[comp[v]].pb(comp[u]);
                        }
                    }
                }
                brid(0, -1);
                if(!bridge) puts("1");
                else puts("2");
            }
        }
    }
}

