#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 105;
const ll MOD = 1e9+7;
int n, k;
vector<int> adj[N];
bool vis[N], inst[N];
int st[N], ps, cs, cyc[N], sz[N];

void clear() {
    ps = cs = 0;
    for(int u = 0; u < n; u++){
        adj[u].clear();
        cyc[u] = -1;
        vis[u] = false;
        inst[u] = false;
    }
}

void dfs(int u, int p = -1) {
    st[ps++] = u;
    inst[u] = true;
    vis[u] = true;
    int par = 0;
    for(int v : adj[u]) {
        if(v == p) par++;
        if(!vis[v]) dfs(v, u);
        else if(inst[v] && (v != p || par > 1)) {
            cyc[v] = cs;
            sz[cs] = 1;
            for(int i = ps-1; st[i] != v; i--) {
                cyc[st[i]] = cs;
                sz[cs]++;
            }
            cs++;
        }
    }
    ps--;
    inst[u] = false;
}

void mark_cycle() {
    for(int u = 0; u < n; u++)
        if(!vis[u])
            dfs(u);
}

int get_sz(int u, int p = -1) {
    int ret = 1;
    for(int v : adj[u]) 
        if(v != p && cyc[v] == -1)
            ret += get_sz(v, u);
    return ret;
}

ll exp(ll b, int e) {
    ll ret = 1;
    for(int i = 0; i < e; i++)
        ret = (ret * b) % MOD;
    return ret;
}

ll count_trees(int c) {
    ll ans = 1;
    for(int u = 0; u < n; u++)
        if(cyc[u] == c)
            ans = (ans * exp(k-1, get_sz(u)-1)) % MOD;
    return ans;
}

ll count_cyc(int c) {
    ll ans = exp(k-1, sz[c]);
    if(sz[c]&1) ans = (ans + MOD - ll(k-1)) % MOD;
    else ans = (ans + ll(k-1)) % MOD;
    return ans;
}

ll solve() {
    ll ans = 1;
    for(int i = 0; i < cs; i++) {
        ll loc = (count_trees(i) * count_cyc(i)) % MOD;
        ans = (ans * loc) % MOD;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);
        clear();
        for(int u = 0; u < n; u++) {
            int v;
            scanf("%d", &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }

        mark_cycle();
        /* cout << "Cyc size: " << cs << endl; */
        /* for(int u = 0; u < n; u++) if(cyc[u]) cout << u << " "; */
        /* cout << endl; */

        /* cout << "Cyc: " << c << endl; */
        /* cout << "Tree: " << s << endl; */
        printf("%lld\n", solve() % MOD);
    }

}

