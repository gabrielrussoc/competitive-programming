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
const int M = 402004;
const int modn = 1000000007;

int n, m, es, tempo, turn;
int head[N], to[M], nx[M], brid[M], bridge;
int low[N], d[N], vis[N], pai[N], lv[N];

void dfs (int u, int p, int l) {
    lv[u] = l;
    vis[u] = turn;
    low[u] = d[u] = tempo++;
    int k = 0;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(v == p) k++;
        if(vis[v] != turn) {
            pai[v] = u;
            dfs(v, u, l+1);
            low[u] = min(low[u], low[v]);
            if(low[v] > d[u]) brid[e] = brid[e^1] = 1;
        } else if (k > 1) low[u] = min(low[u], d[v]);
    }
}

int main() {
    int tc = 1;
    while(scanf("%d %d",&n,&m) && n) {
        es = 2; tempo = bridge = 0;
        for(int i = 0; i < n; i++) head[i] = 0;
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d",&u,&v);
            u--; v--;
            to[es] = v; nx[es] = head[u]; head[u] = es++;
            to[es] = u; nx[es] = head[v]; head[v] = es++;
        }
        dfs(0,-1,0);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",tc++);
        while(q--) {
            int a,b;
            scanf("%d %d",&a,&b); a--; b--;
            if(lv[a] > lv[b]) swap(a,b);
        }
        putchar('\n');
        turn++;
    }
}

