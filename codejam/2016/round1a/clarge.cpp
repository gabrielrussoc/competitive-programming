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
const int modn = 1000000007;

int t, n, tempo, low[N], d[N], st[N], instac[N], vis[N], uf[N], wf[N], ps, comp[N], cp;
vector<int> adj[N];

void dfs (int u) {
    vis[u] = 1;
    low[u] = d[u] = tempo++;
    st[ps++] = u;
    instac[u] = 1;
    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (instac[v]) low[u] = min(low[u],d[v]);
    }
    if(low[u] == d[u]) {
        int v;
        do {
            v = st[--ps];
            instac[v] = 0;
            comp[v] = cp;
        } while (u != v);
        cp++;
    }
}

int find (int i) {
    if(uf[i] == i) return i;
    return uf[i] = find(uf[i]);
}

void join (int i, int j) {
    i = find(i); j = find(j);
    if(i == j) return;
    if(wf[i] > wf[j]) swap(i,j);
    wf[j] += wf[i];
    uf[i] = j;
}

int main() {
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        tempo = cp = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++) {
            adj[i].clear();
            vis[i] = 0;
            uf[i] = i;
            wf[i] = 1;
        }
        int bf;
        for(int i = 0; i < n; i++) {
            scanf("%d",&bf);
            bf--;
            adj[i].pb(bf);
        }
        for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(comp[i] == comp[j]) join(i,j);
        
        int ans = 0;
        for(int i = 0; i < n; i++) if (uf[i] == i) ans = max(ans, wf[i]);
        printf("Case #%d: %d\n",tc,ans);
    }
}

