#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int PL = 17;
const int N = 20004;
const int inf = 0x3f3f3f3f;
int n, P, m, g, T;
int p[PL], t[PL];
int d[N], vis[N], turn;
int dis[PL][1<<PL][2], visi[PL][1<<PL][2];

struct edge {
    int v, w;
    edge () {}
    edge(int v, int w) : v(v), w(w) {}
    bool operator<(const edge &o) const {
        return w > o.w;
    }
};
struct state {
    int v, mask, d, taxi;
    state(){}
    state(int v, int mask, int taxi, int d) : v(v), mask(mask), d(d), taxi(taxi) {}
    bool operator<(const state &o) const {
        return d > o.d;
    }
};
vector<edge> adj[N];
vector<edge> cadj[PL];

void dij(int s) {
    turn++;
    for(int u = 0; u < n; u++) d[u] = inf;
    priority_queue<edge> pq;
    d[s] = 0;
    pq.push(edge(s, d[s]));
    while(!pq.empty()) {
        int u = pq.top().v;
        pq.pop();
        if(vis[u] == turn) continue;
        vis[u] = turn;
        for(edge &e : adj[u]) {
            int v = e.v;
            int w = e.w;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(edge(v, d[v]));
            }
        }
    }
}

void compress(){
    for(int i = 0; i < P; i++) {
        int u = p[i];
        dij(u);          
        for(int j = 0; j < P; j++) {
            int v = p[j];
            cadj[i].pb(edge(j, d[v]));
        }
    }
}

void solve() {
    int s = 0;
    for(int i = 0; i < P; i++) if(p[i] == 0) s = i;
    for(int u = 0; u < P; u++)
        for(int mask = 0; mask < (1<<P); mask++)
            for(int taxi = 0; taxi < 2; taxi++)
                dis[u][mask][taxi] = inf;
    priority_queue<state> pq;
    dis[s][0][false] = 0;
    pq.push(state(s, 0, false, 0));
    while(!pq.empty()) {
        int u = pq.top().v;
        int mask = pq.top().mask;
        int taxi = pq.top().taxi;
        pq.pop();
        if(visi[u][mask][taxi]) continue;
        visi[u][mask][taxi] = 1;
        for(edge e : cadj[u]) {
            int v = e.v;
            int w = e.w;
            int nmask = mask | (1<<u);
            if(dis[v][nmask][taxi] > dis[u][mask][taxi] + w + t[u]) {
                dis[v][nmask][taxi] = dis[u][mask][taxi] + w + t[u];
                pq.push(state(v, nmask, taxi, dis[v][nmask][taxi]));
            }
            if(!taxi) {
                if(dis[v][nmask][true] > dis[u][mask][taxi] + T + t[u]) {
                    dis[v][nmask][true] = dis[u][mask][taxi] + T + t[u];
                    pq.push(state(v, nmask, true, dis[v][nmask][true]));
                }
            }
        }
    }
    int mask = (1 << P) - 1;
    if(dis[s][mask][false] <= g) puts("possible without taxi");
    else if(dis[s][mask][true] <= g) puts("possible with taxi");
    else puts("impossible");
}

int main() {
    scanf("%d %d %d %d %d", &n, &P, &m, &g, &T);

    for(int i = 0; i < P; i++) scanf("%d %d", p+i, t+i);
    if(*min_element(p, p+P) != 0) {
        p[P] = 0;
        t[P] = 0;
        P++;
    }

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].pb(edge(v,w));
        adj[v].pb(edge(u,w));
    }

    compress();
    solve();
}
    

