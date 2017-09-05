#include <bits/stdc++.h>
#define pb push_back
#define wei first
#define vert second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 10004;
const int inf = 0x3f3f3f3f;

struct node {
    int u, d, p;
    node () {}
    node (int u, int d, int p) : u(u), d(d), p(p) {}

    bool operator<(const node &o) const {
        return d > o.d;
    }
};

int n, m;
int d[N][2], vis[N][2];
vector<pii> adj[N];

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        d[i][0] = d[i][1] = inf;
    }

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w); u--; v--;
        adj[u].pb(pii(w, v));
        adj[v].pb(pii(w, u));
    }

    priority_queue<node> pq;
    pq.push(node(0, 0, 0));
    d[0][0] = 0;
    while(!pq.empty()) {
        node at = pq.top();
        pq.pop();
        int u = at.u, p = at.p;
        if(vis[u][p]) continue;
        vis[u][p] = 1;
        for(pii e : adj[u]) {
            int v = e.vert;
            int w = e.wei;
            if(d[v][!p] > d[u][p] + w) {
                d[v][!p] = d[u][p] + w;
                pq.push(node(v, d[v][!p], !p));
            }
        }
    }
    printf("%d\n", d[n-1][0] != inf ? d[n-1][0] : -1);
}

