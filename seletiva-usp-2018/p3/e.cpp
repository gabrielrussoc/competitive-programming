#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
const int K = 20;
int t, n, q;
int l[N][K], dep[N], val[N], bal[N], up[N], down[N];
vector<int> adj[N];
map<int, vector<int>> above;

void clear() {
    for(int u = 0; u < n; u++) adj[u].clear();
    above.clear();
    bal[N-1] = 0;
    dep[N-1] = -1;
    above[0].pb(N-1);
}

void dfs (int u, int p, int d) {
    l[u][0] = p; dep[u] = d; 
    for(int i = 1; i < K; i++)
        l[u][i] = l[l[u][i-1]][i-1];
    
    bal[u] = val[u];
    if(d > 0) bal[u] += bal[p];
    
    if(val[u] == -1) {
        up[u] = 0;
        if(!above[bal[u]-1].empty())
            down[u] = dep[u] - dep[above[bal[u]-1].back()] - 1;
        else
            down[u] = dep[u] + 1;
    } else {
        down[u] = 0;
        if(!above[bal[u]+1].empty())
            up[u] = dep[u] - dep[above[bal[u]+1].back()] - 1;
        else
            up[u] = dep[u] + 1;
    }
    above[bal[u]].pb(u);
    for(int v : adj[u])
        if(v != p) dfs(v, u, d + 1);
    above[bal[u]].pop_back();
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u,v);
    if(dep[u] < dep[v]) {
        for(int i = K-1; i >= 0; i--)
            if(dep[l[v][i]] >= dep[u])
                v = l[v][i];
    }
    if(u == v) return v;
    for(int i = K-1; i >= 0; i--)
        if(l[v][i] != l[u][i])
           v = l[v][i], u = l[u][i];
   return l[v][0]; 
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> q;
        clear();
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i = 0; i < n; i++) {
            char c;
            cin >> c;
            val[i] = c == '(' ? 1 : -1;
        }
        dfs(0, 0, 0);
        for(int i = 0; i < q; i++) {
            int u, v;
            cin >> u >> v; u--; v--;
            int w = lca(u, v);

            int balp = w ? bal[l[w][0]] : 0;
            int balance = bal[u] + bal[v] - 2*balp - val[w];
            if(up[u] >= dep[u] - dep[w] + 1 && down[v] >= dep[v] - dep[w] && balance == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}

