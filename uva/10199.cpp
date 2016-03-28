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
const int N = 104;
const int modn = 1000000007;

int n, r, k, es;
vector<string> ans;
map<string, int> m;
string s, t;
int head[N], to[N*N], nx[N*N], cut[N], vis[N], tempo;
int low[N], d[N], raiz;

void dfs(int u, int p) {
    vis[u] = 1;
    low[u] = d[u] = tempo++;
    int child = 0;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(!vis[v]) {
            child++;
            dfs(v,u);
            low[u] = min(low[u], low[v]);
            if(u != raiz && low[v] >= d[u]) cut[u] = 1;
            else if(u == raiz && child > 1) cut[u] = 1; 
        } else if (v != p) low[u] = min(low[u], d[v]);
    }
}

int main() {
    int tc = 1;
    bool blank = false;
    while(scanf("%d",&n) && n) {
        if(blank) printf("\n");
        blank = true;
        tempo = 0;
        m.clear();
        es = 2;
        for(int i = 0; i < n; i++) head[i] = vis[i] = cut[i] = 0;
        ans.clear();
        for(int i = 0; i < n; i++) {
            cin >> s;
            m[s] = i;
        }
        scanf("%d",&r);
        while(r--) {
            cin >> s >> t;
            int u = m[s], v = m[t];
            to[es] = v; nx[es] = head[u]; head[u] = es++;
            to[es] = u; nx[es] = head[v]; head[v] = es++;
        }
        for(int i = 0; i < n; i++) if(!vis[i]) { raiz = i; dfs(i,-1); }
        for(auto it : m) 
            if(cut[it.second]) ans.pb(it.first);
        sort(ans.begin(), ans.end());
        printf("City map #%d: %d camera(s) found\n",tc++,int(ans.size()));
        for(string p : ans) cout << p << endl;
        
    }
}

