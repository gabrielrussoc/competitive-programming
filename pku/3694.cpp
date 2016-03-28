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
int head[N], to[M], nx[M], bridge;
int low[N], d[N], vis[N];

void dfs (int u, int p) {
    vis[u] = turn;
    low[u] = d[u] = tempo++;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(vis[v] != turn) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > d[u]) bridge++, printf("%d %d\n",to[e],to[e^1]);
        } else if (v != p) low[u] = min(low[u], d[v]);
    }
}

int main() {
    int tc = 1;
    while(scanf("%d %d",&n,&m) && n) {
        es = 2; tempo = 0;
        for(int i = 0; i < n; i++) head[i] = 0;
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d",&u,&v);
            u--; v--;
            to[es] = v; nx[es] = head[u]; head[u] = es++;
            to[es] = u; nx[es] = head[v]; head[v] = es++;
        }
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",tc++);
        while(q--) {
            tempo = 0;
            turn++;
            bridge = 0;
            int a,b;
            scanf("%d %d",&a,&b); a--; b--;
            to[es] = b; nx[es] = head[a]; head[a] = es++;
            to[es] = a; nx[es] = head[b]; head[b] = es++;
            dfs(0,-1);
            printf("%d\n",bridge);
        }
        putchar('\n');
    }
}

