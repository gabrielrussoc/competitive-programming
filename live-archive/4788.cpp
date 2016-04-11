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

int n, cost[N], die[N], stay[N], qtd;
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

bool can (int k) {
    for(int i = 0; i < n; i++){
        qtd = k;
        if (dfs(i,i)) return true;
    }
    return false;
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
        for(int i = 0; i < n; i++) sort(adj[i].begin(), adj[i].end(), comp);
        int lo = 0, hi = INT_MAX;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if(can(mid)) hi = mid;
            else lo = mid+1;
        }
        printf("Case %d: %d\n",tc++,lo);
    }
}

