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
const int N = 504;
const int modn = 1000000007;

int vis[N], low[N], d[N], instac[N], st[N];
int ps, tempo, k;
int adj[N][N], kadj[N][N], kwei[N][N], wei[N][N];
int comp[N], n, m;

void dfs(int u) {
    vis[u] = 1;
    low[u] = d[u] = tempo++;
    st[ps++] = u;
    instac[u] = 1;
    for(int v = 0; v < n; v++) {
        if(adj[u][v]) {
            if(!vis[v]) {
                dfs(v);
                low[u] = min(low[u],low[v]);
            } else if (instac[v]) {
                low[u] = min(low[u], d[v]);
            }
        }
    }
    if(low[u] == d[u]) {
        int v;
        do {
            v = st[--ps];
            instac[v] = 0;
            comp[v] = k;
        } while (v != u);
        k++;
    }
}

int main() {
    while(scanf("%d %d",&n,&m) && n) {
        memset(adj,0,sizeof adj);
        memset(kadj,0,sizeof kadj);
        memset(vis,0,sizeof vis);
        tempo = 0;
        k = 0;
        for(int i = 0; i < m; i++) {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            u--; v--;
            adj[u][v] = 1; wei[u][v] = w;
        }
        for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);
        for(int i = 0; i < k; i++) for(int j = 0; j < k; j++) { if(i == j) continue; kwei[i][j] = 123456; }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(comp[i] != comp[j] && adj[i][j]) kadj[comp[i]][comp[j]] = 1, kwei[comp[i]][comp[j]] = min(kwei[comp[i]][comp[j]],wei[i][j]);
        
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(j == i) continue;
                for(int l = 0; l < k; l++)
                    kwei[i][j] = min(kwei[i][j], kwei[i][l] + kwei[l][j]);
            }
        }
        int x, a, b;
        scanf("%d",&x);
        while(x--) {
            scanf("%d %d",&a,&b);
            a--; b--;
            if(kwei[comp[a]][comp[b]] == 123456) puts("Nao e possivel entregar a carta");
            else printf("%d\n",kwei[comp[a]][comp[b]]);
        }
        putchar('\n');
    }
}

