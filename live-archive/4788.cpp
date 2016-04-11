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
const int N = 103;
const int modn = 1000000007;

int n, cost[N], die[N], stay[N];
vector<int> adj[N];

bool dfs(int u, int p) {
    if (qtd < cost[u]) return false;
    qtd -= die[u] + stay[u];
    if (qtd < 0) return false;
    for(int v : adj[u]) 
        if (v != p) if(!dfs(v,u)) return false;
    return true;
}

bool comp (int i, int j) {
    return cost[i] > cost[j];
}

int main() {
    int tc = 1;
    while(scanf("%d",&n) && n) {
        for(int i = 0; i < n; i++) 
            scanf("%d %d %d",cost+i,die+i,stay+i), adj[i].clear();

        int u, v;
        for(int i = 0; i < n-1; i++) {
            scanf("%d %d",&u,&v); u--; v--;
            adj[u].pb(v); adj[v].pb(u);
        }
        dfs(0,0);
        printf("Case %d: %d\n",tc++,ans[0]);
    }
}

