#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;
int t, n, m, k, g[N], f[N], d[N], vis[N], p[N], turn;
vector<int> adj[N];

void safe() {
    stack<int> s;
    for(int i = 0; i < n; i++) if(g[i] == 1) s.push(i);
    for(int i = 0; i < n; i++) f[i] = 1;
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        f[u] = 0;
        for(int v : adj[u]) {
            g[v]--;
            if(g[v] == 1) s.push(v);
        }
    }
}   

void get_dists() {
    turn++;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(f[i]) {
            q.push(i);
            d[i] = 0;
            vis[i] = turn;
            p[i] = i;
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(vis[v] != turn) {
                d[v] = d[u] + 1;
                vis[v] = turn;
                q.push(v);
                p[v] = u;
            }
        }
    }
}

void update_max() {
    int u = 0, b;
    b = -1;
    for(int i = 0; i < n; i++) {
        if(!f[i] && d[i] > b) {
            b = d[i];
            u = i;
        }
    }
    while(p[u] != u) {
        f[u] = 1;
        u = p[u];
    }
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 0; i < n; i++) {
            adj[i].clear();
            g[i] = 0;
        }
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v); u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
            g[u]++;
            g[v]++;
        }
        safe();
        while(k--) {
            get_dists();
            update_max();
        }
        int ans = 0;
        for(int i = 0; i < n; i++) if(!f[i]) ans++;
        printf("%d\n", ans);
    }
}

