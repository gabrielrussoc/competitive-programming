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

int n, need[N], back[N], tneed[N], tback[N];
vector<int> adj[N];

bool comp (int i, int j) {
    return tback[i] > tback[j];
}

int dfs(int u, int p) {
    tneed[u] = need[u]; tback[u] = back[u];
    vector<int> filho;
    for(int v : adj[u]) 
        if (v != p) {
            dfs(v, u);
            filho.pb(v);
        }
    sort(filho.begin(), filho.end(), comp);
    for(int f : filho) {
        tneed[u] += max(0, tneed[f] - tback[u]);
        tback[u] -= min(tback[u], tneed[f]);
        tback[u] += tback[f];
    }
    return tneed[u];
}

int main() {
    int tc = 1,u, v, a, m, g;
    while(scanf("%d",&n) && n) {
        for(int i = 0; i < n; i++) {
            scanf("%d %d %d",&a,&m,&g);
            m += g;
            need[i] = max(a,m);
            back[i] = need[i] - m;
            adj[i].clear();
        }

        for(int i = 0; i < n-1; i++) {
            scanf("%d %d",&u,&v); u--; v--;
            adj[u].pb(v); adj[v].pb(u);
        }
        int ans = inf;
        for(int i = 0; i < n; i++) ans = min (ans, dfs(i,i));
        printf("Case %d: %d\n",tc++, ans);
    }
}

