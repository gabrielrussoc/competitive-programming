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
const int modn = 1000000007;

int n, m;
int vis[N];
vector<int> adj[N];

void fail() {
    puts("-1");
    exit(0);
}

void dfs(int u, int k) {
    if(vis[u] == (k^1)) fail();
    if(vis[u] == k) return;
    vis[u] = k;
    for (int v : adj[u]) dfs(v, k^1);
}

void show(int k) {
    int cont = 0;
    for(int i = 0; i < n; i++) if(vis[i] == k) cont++;
    printf("%d\n", cont);
    for(int i = 0; i < n; i++) if(vis[i] == k) printf("%d ",i+1);
    putchar('\n');
} 

int main() {
    scanf("%d %d",&n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d",&u,&v); u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(i, 2);
    show(2);
    show(3);
}

