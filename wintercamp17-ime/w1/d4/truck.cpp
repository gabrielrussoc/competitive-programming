#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

struct edge {
    int v, w;
    edge() {}
    edge(int v, int w) : v(v), w(w) {}
};

const int N = 105;
const int inf = 0x3f3f3f3f;
int n, z;
vector<edge> adj[N];
int turn, vis[N][N], memo[N][N], root;

int dp(int u, int k) {
    if(k == 0) return u == root ? 0 : -inf;
    int &me = memo[u][k];
    if(vis[u][k] == turn) return me;
    vis[u][k] = turn;
    me = -inf;
    for(edge e : adj[u]) {
        int v = e.v;
        int w = e.w;
        me = max(me, dp(v, k-1) + w);
    }
    return me;
}

int main() {
    scanf("%d %d", &n, &z);
    for(int i = 0; i < z; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w); u--; v--;
        adj[u].pb(edge(v, w));
    }
    double ans = 0;
    for(root = 0; root < n; root++) {
        turn++;   
        for(int k = 1; k <= n; k++) {
            double loc = dp(root, k);
            ans = max(ans, loc / double(k));
        }
    }
    printf("%.20lf\n", ans);

}

