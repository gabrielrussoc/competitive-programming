#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 3005;
const int inf = 0x3f3f3f3f;
int n, m, d[N];
ll c[N];
vector<int> adj[N];

ll bfs(int s) {
    for(int u = 0; u < n; u++) d[u] = inf, c[u] = 0;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(d[u] == 2) break;
        for(int v : adj[u]) {
            if(d[v] > d[u] + 1) {
                d[v] = d[u]+1;
                q.push(v);
            }
            if(d[u] == 1) c[v]++;
        }
    }
    ll ret = 0;
    for(int u = 0; u < n; u++)
        if(d[u] == 1 || d[u] == 2)
            ret += c[u]*(c[u] - 1ll) / 2ll;
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        adj[u].pb(v);
    }
    ll ans = 0;
    for(int u = 0; u < n; u++)
        ans += bfs(u);
    printf("%lld\n", ans);

}

