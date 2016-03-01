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
const int N = 500004;
const int modn = 1000000007;

string ss;
char s[N];
pll ans[N], ans2[N];
map<string, int> m;
vector<string> v;
vector<int> adj[N];
vector<int> adj2[N];

int k = 1,n, mm, vis[N];
int tim = 1, tp = -1, sc;
int disc[N], low[N], stac[N], instac[N], comp[N];

void scc (int u) {
    disc[u] = low[u] = tim++;
    stac[++tp] = u;
    instac[u] = 1;
    
    for(int v : adj[u]) {
        if(!disc[v]) {
            scc(v);
            low[u] = min(low[u],low[v]);
        } else if (instac[v])
            low[u] = min(low[u], disc[v]);
    }
    int v;
    if(low[u] == disc[u]) {
        do {
            v = stac[tp--];
            comp[v] = sc;
            instac[v] = 0;
        } while (u != v);
        sc++;
    }
}

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1; 
    for(int v : adj2[u]){
        dfs(v);
        ans2[u] = min(ans2[u], ans2[v]);
    }
}

void lowerize() {
    for(int j = 0; s[j]; j++) s[j] = tolower(s[j]);
}

void label() {
    m[ss] = k++;
    int cont = 0, j;
    for(j = 0; s[j]; j++) if(s[j] == 'r') cont++;
    ans[k-1] = pii(cont,j);
}

int main() {
    scanf("%d",&mm);
    for (int i = 0; i < mm; i++){
        scanf(" %s", s); lowerize(); ss = s;
        if(!m[ss]) label();
        v.pb(ss);
    }
    scanf("%d",&n);
    int a,b;
    for(int i = 0; i < n; i++){
        scanf(" %s", s); lowerize(); ss = s;
        if(!m[ss]) label();
        a = m[ss];
        
        scanf(" %s", s); lowerize(); ss = s;
        if(!m[ss]) label();
        b = m[ss];
        
        adj[a].pb(b);
    }
    for (int i = 1; i < k; i++) if(!disc[i]) scc(i);
    for (int i = 0; i < sc; i++) ans2[i] = pii(inf,inf);
    for (int i = 1; i < k; i++) ans2[comp[i]] = min(ans2[comp[i]],ans[i]);

    for(int u = 1; u < k; u++) 
        for(int v : adj[u]) 
            if(comp[u] != comp[v]) 
                adj2[comp[u]].pb(comp[v]);
    
    for(int u = 0; u < sc; u++) if(!vis[u]) dfs(u);

    ll t, r;
    t = r = 0;
    for(int i = 0; i < mm; i++) r += ans2[comp[m[v[i]]]].ff, t += ans2[comp[m[v[i]]]].ss; 
    cout << r << " " << t << endl;
}

