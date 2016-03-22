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
const int N = 404;
const int modn = 1000000007;

int tc = 1, tempo;
int es, head[N], to[N*N], nx[N*N], n, m, cut[N], low[N], d[N], vis[N];

void dfs(int u, int p) {
    vis[u] = 1;
    int child = 0;
    low[u] = d[u] = tempo++;
    for(int e = head[u]; e; e = nx[e]) {
        child++;
        int v = to[e];
        if(!vis[v]) {
            dfs(v, u);
            low[u] = min(low[u],low[v]);
            if(u == 1 && child > 1) cut[u] = 1; 
            else if (u != 1 && low[v] >= d[u]) cut[u] = 1; 
        } else if (v != p) {
            low[u] = min (low[u], d[v]);
        }
    }
}


int main() {
    while(scanf("%d %d",&n,&m) && n) {
        tempo = 0;
        memset(head,0,sizeof head);
        memset(vis,0,sizeof vis);
        memset(cut,0,sizeof cut);
        es = 2;
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d",&u,&v);
            to[es] = v; nx[es] = head[u]; head[u] = es++;  
            to[es] = u; nx[es] = head[v]; head[v] = es++;
        }
        dfs(1,0);
        printf("Teste %d\n",tc++);
        bool f = false;
        for(int i = 1; i <= n; i++)
            if(cut[i]) printf("%d ",i), f = true;
        if(!f) printf("nenhum");
        printf("\n\n");
    }
}

