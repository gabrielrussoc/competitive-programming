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
const int N = 20004;
const int M = 50004;
const int modn = 1000000007;

int n, m, t, tempo, ps, cs, es;
int to[M], head[N], nx[M], vis[N], low[N], d[N], instac[N], st[N], comp[N];
int in[N], out[N], qi, qo;

void dfs (int u) {
    vis[u] = 1;
    st[ps++] = u;
    instac[u] = 1;
    low[u] = d[u] = tempo++;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(!vis[v]) {
            dfs(v);
            low[u] = min(low[u],low[v]);
        } else if (instac[v]) low[u] = min(low[u], d[v]);
    }
    if (low[u] == d[u]) {
        int v;
        do {
            v = st[--ps];
            comp[v] = cs;
            instac[v] = 0;
        } while (v != u);
        cs++;
    }
}

int main() {
    scanf("%d",&t);
    while(t--) {
        es = 2; tempo = cs = qi = qo = 0;
        scanf("%d %d",&n,&m);
        for(int i = 0; i < n; i++) head[i] = vis[i] = in[i] = out[i] = 0;
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d",&u, &v);
            u--; v--;
            to[es] = v; nx[es] = head[u]; head[u] = es++;
        }
        for(int u = 0; u < n; u++) if(!vis[u]) dfs(u);
        for(int u = 0; u < n; u++) {
            for (int e = head[u]; e; e = nx[e]){
                int v = to[e];
                if (comp[u] != comp[v]){
                    out[comp[u]]++;
                    in[comp[v]]++;
                }
            }
        }
        if(cs == 1) {
            printf("0\n");
            continue;
        }
        for(int u = 0; u < cs; u++) {
            if(out[u] == 0) qo++;
            if(in[u] == 0) qi++;
        }
        printf("%d\n",max(qo, qi));
    }
}

