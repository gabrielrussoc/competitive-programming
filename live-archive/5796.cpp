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
const int N = 10004;
const int M = 100004;
const int modn = 1000000007;

int wf[N], uf[N], head[N], nx[2*M], to[2*M];
int es, n, m, q;
int low[N], d[N], bridge[2*M], tempo, vis[N];


int find (int i) {
    if (i == uf[i]) return i;
    return uf[i] = find(uf[i]);
}

void join (int i, int j) {
    i = find(i); j = find(j);
    if(i == j) return;
    if(wf[i] > wf[j]) swap(i,j);
    wf[j] += wf[i];
    uf[i] = j;
}

void dfs(int u, int p) {
    vis[u] = 1;
    low[u] = d[u] = tempo++;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if (!vis[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > d[u]) join(u,v);
        } else if (v != p) low[u] = min(low[u], d[v]); 
    }
}

int main() {
    while(scanf("%d %d %d", &n, &m, &q) && n) {
        for(int i = 0; i < n; i++) uf[i] = i, wf[i] = 1, head[i] = vis[i] = 0;
        es = 2; tempo = 0;
        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d %d",&u, &v);
            u--; v--;
            to[es] = v; nx[es] = head[u]; head[u] = es++;
            to[es] = u; nx[es] = head[v]; head[v] = es++;
        }
        for(int i = 0; i < n; i++) if(!vis[i]) dfs(i, -1);
        while(q--) {
            scanf("%d %d",&u, &v);
            u--; v--;
            if (find(u) == find(v)) puts("Y");
            else puts("N");
        }
        puts("-");
    }

}

