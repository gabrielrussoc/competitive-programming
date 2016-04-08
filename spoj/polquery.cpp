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
const int N = 100005;
const int M = 500005;
const int modn = 1000000007;

int n, m, es, tempo;
int head[N], to[2*M], nx[2*M], low[N], d[N], f[N], vis[N], cut[N];
map<pii, int> bd;
vector<int> adj[N];

void dfs (int u, int p) {
    vis[u] = 1;
    low[u] = d[u] = tempo++;
    int nf = 0;
    for(int e = head[u]; e; e = nx[e]){
        int v = to[e];
        if(!vis[v]) {
            adj[u].pb(v);
            dfs(v, u); nf++;
            low[u] = min(low[u], low[v]);
            if(low[v] > d[u]) bd[pii(u,v)] = 1;
            if(u && low[v] >= d[u]) cut[u] = 1; 
            if(!u && nf > 1) cut[u] = 1;
        } else if (v != p) low[u] = min(low[u], d[v]);
    }
    f[u] = tempo++;
}

bool inside(int a, int b) { //b filho de a
    return d[a] <= d[b] && f[a] >= f[b];
}

bool compare (int i, int j) {
    return d[i] < d[j];
}

int comp (int a, int u) {
    if(inside(u,a)) {
        int f = *(upper_bound(adj[u].begin(), adj[u].end(), a, compare)-1);
        if(low[f] >= d[u]) return f;
        return -1;
    }
    return -1;
}

int main() {
    es = 2;
    int q, t, a, b, c, u, v;
    scanf("%d %d",&n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--; v--;
        to[es] = v; nx[es] = head[u]; head[u] = es++;
        to[es] = u; nx[es] = head[v]; head[v] = es++;
    }
    dfs(0,-1);
    scanf("%d",&q);
    while(q--) {
        scanf("%d %d %d %d",&t,&a,&b,&u); a--; b--; u--;
        if(t == 1) {
            scanf("%d",&v); v--;
            if(d[u] > d[v]) swap(u,v);
            if(!bd.count(pii(u,v))) puts("da");
            else if (inside(v,a) == inside(v,b)) puts("da");
            else puts("ne");
        } else {
            if(!cut[u]) puts("da");
            else if(comp(a,u) == comp(b,u)) puts("da");
            else puts("ne");
        }
    }   
}

