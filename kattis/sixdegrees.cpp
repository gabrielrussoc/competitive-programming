#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 3005;

int t, m, n;
int vis[N], d[N], turn;
map<string, int> id;
vector<int> adj[N];

int get(const string &s) {
    if(!id.count(s)) id[s] = n++;
    return id[s];
}

void init() {
    n = 0;
    for(int u = 0; u < N; u++) adj[u].clear();
    id.clear();
}

bool bfs(int s) {
    turn++;
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        if(d[u] >= 6) break;
        q.pop();
        for(int v : adj[u]) {
            if(vis[v] != turn) {
                q.push(v);
                d[v] = d[u] + 1;
                vis[v] = turn;
            }
        }
    }
    for(int u = 0; u < n; u++) if(vis[u] != turn) return false;
    return true;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        init();
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            string s, t;
            cin >> s >> t;
            int u = get(s);
            int v = get(t);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int ans = 0;
        for(int u = 0; u < n; u++)
            if(!bfs(u)) ans++;
        puts(20*ans > n ? "NO" : "YES");
    }
}

