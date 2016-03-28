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
const int M = 50004;
const int N = 1004;
const int modn = 1000000007;

int head[N], to[2*M], nx[2*M], bridge, vis[N];
int low[N], d[N];
int n,m, tempo, es;

void dfs(int u, int p) {
    vis[u] = 1;
    low[u] = d[u] = tempo++;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(!vis[v]) {
            dfs(v, u);
            low[u] = min(low[u],low[v]);
            if(low[v] > d[u]) bridge = 1;
        } else if (v != p) low[u] = min(low[u], d[v]);
    }
}

int main() {
    while(scanf("%d %d",&n,&m) && n) {
        es = 2;
        tempo = bridge = 0;
        for(int i = 0; i <= n; i++) head[i] = vis[i] = 0;
        for(int i = 0; i < m; i++) {
            int a,b;
            scanf("%d %d",&a,&b);
            to[es] = b; nx[es] = head[a]; head[a] = es++;
            to[es] = a; nx[es] = head[b]; head[b] = es++;
        }
        dfs(1, 0);
        if(bridge) putchar('N');
        else putchar('S');
        putchar('\n');
    }
}

