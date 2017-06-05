#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 205;

struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {} 
    int distTo(const point &o) const {
        return abs(x - o.x) + abs(y - o.y);
    }
};

struct edge {
    int v, dist;
    edge() {}
    edge(int v, int dist) : v(v), dist(dist) {}
};

int n, M[N], turn;
int vis[N];
point stud[N], prof[N];
vector<edge> adj[N];

bool dfs(int u, int k) {
    if(vis[u] == turn) return false;
    vis[u] = turn;
    for(edge e : adj[u]) {
        int v = e.v;
        int dist = e.dist;
        if(dist > k) continue;
        if(M[v] == -1 || dfs(M[v], k)) {
            M[u] = v;
            M[v] = u;
            return true;
        }
    }
    return false;
}

bool can(int k) {
    int ans = 0;
    for(int u = 0; u < 2*n; u++) {
        M[u] = -1;
    }
    for(int u = 0; u < n; u++) {
        turn++;
        if(dfs(u, k)) ans++;
    }
    return ans == n;
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        stud[i] = point(x, y);
    }

    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        prof[i] = point(x, y);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int u = i;
            int v = n + j;
            int dist = stud[i].distTo(prof[j]);
            adj[u].pb(edge(v, dist));
            adj[v].pb(edge(u, dist));
        }
    }

    int lo = 0, hi = 5e8;
    while(lo < hi) {
        int mid = (lo + hi)/2;
        if(can(mid)) hi = mid;
        else lo = mid + 1;
    }
    printf("%d\n", lo);
}

