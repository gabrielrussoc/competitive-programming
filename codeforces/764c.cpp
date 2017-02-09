#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 212345;

int n, c[N], deg[N], vis[N], ans;
vector<int> adj[N];

void dfs(int u, int m){
    vis[u] = m;
    for(int v : adj[u])
        if(c[v] == m && !vis[v])
            dfs(v, m);
}

void get(int u, int p, int m) {
    if(vis[u] == 0 || vis[u] != m) {
        ans = u;
        return;
    }
    for(int v : adj[u]) 
        if(v != p) get(v, u, m);
}

bool check(int u, int p, int m, int ans) {
    if(c[u] != m) return false;
    for(int v : adj[u]) {
        if(u == ans) m = c[v];
        if(v != p) if(!check(v, u, m, ans)) return false; 
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d",&u, &v); u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++; deg[v]++;
    }
    for(int i = 0; i < n; i++) scanf("%d", c+i);
    for(int i = 0; i < n; i++) if(deg[i] == 1 && !vis[i]) dfs(i, c[i]);
    int bl = 0;
    for(int i = 0; i < n; i++) if(vis[i] == 0) bl++;
    if(bl > 1) puts("NO");
    else {
        get(0, -1, c[0]);
        int ans1 = ans;
        for(int v : adj[ans]) if(c[v] != c[ans]) ans1 = v;
        if(check(ans, -1, c[ans], ans)) {
            puts("YES");
            printf("%d\n", ans+1);
        } else if (check(ans1, -1, c[ans1], ans1)) {
            puts("YES");
            printf("%d\n", ans1+1);
        } else puts("NO");
    }
}

