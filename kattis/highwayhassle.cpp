#include <bits/stdc++.h>
#define pb push_back
#define wei first
#define vert second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

const int N = 1003;
const int S = 123;
const int T = 100005;
const int inf = 223456789;
int tc, n, m, s, t, p[N], c, d, dist[N], vis[N], ds[S][T], viss[S][T], turn, f[N];
vector<pii> adj[N], adjc[N];


void reset() {
    for(int i = 0; i < n; i++) {
        adj[i].clear();
        adjc[i].clear();
        p[i] = 0;
        f[i] = -1;
    }
}

void dij(int st){
    turn++;
    priority_queue<pii> pq; 
    pq.push(pii(0,st));
    for(int i = 0; i < n; i++) dist[i] = inf;
    dist[st] = 0;
    while(!pq.empty()){
        int u = pq.top().vert;
        pq.pop();
        if(vis[u] == turn) continue;
        vis[u] = turn;
        for(pii e : adj[u]) {
            int v = e.vert, w = e.wei;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(pii(-dist[v], v));
            }
        }
    }
}

void compress() {
    for(int u = 0; u < n; u++) {
        if(f[u] != -1) {
            dij(u);
            for(int v = 0; v < n; v++) {
                if(u != v && f[v] != -1 && dist[v] != inf) {
                    //printf("Aresta direta %d-%d com peso %d\n", u+1, v+1, dist[v]);
                    int nu = f[u], nv = f[v];
                    adjc[nu].pb(pii(dist[v], nv));
                }
            }
        }
    }
}

int ans() {
    turn++;
    int st = f[c];
    int en = f[d];
    priority_queue<pip> pq;
    for(int i = 0; i <= s; i++)
        for(int j = 0; j <= t; j++)
            ds[i][j] = inf;
    ds[st][0] = 0;
    pq.push(pip(0, pii(st, 0)));
    while(!pq.empty()) {
        pii x = pq.top().vert;
        int u = x.first;
        int g = x.second;    
        //printf("Em %d com %d de gasolina (custa %d)\n", u+1, g, p[u]);
        pq.pop();
        if(viss[u][g] == turn) continue;
        viss[u][g] = turn;
        for(pii e : adjc[u]) {
            int v = e.vert, w = e.wei;
            if(w > t) continue;
            int ng;
            int q;
            if(p[u] > p[v]) {
                if(g > w) continue;
                ng = 0;
                q = (w - g) * p[u];
            } else {
                ng = t - w;
                q = (t - g) * p[u];
            }
            if(ds[v][ng] > ds[u][g] + q) {
                ds[v][ng] = ds[u][g] + q;
                pq.push(pip(-ds[v][ng], pii(v, ng)));
            }
            //printf("\tTentando ir para %d abastecendo %d (custa %d)\n", v + 1, q, p[v]);
        }
    }
    return ds[en][0];
}

int main() {
    scanf("%d", &tc);      
    while(tc--) {
        scanf("%d %d %d", &n, &m, &s);
        scanf("%d", &t);
        reset();
        for(int i = 0; i < m; i++) {
            int a, b, f;
            scanf("%d %d %d", &a, &b, &f);
            a--; b--;
            adj[a].pb(pii(f, b));
            adj[b].pb(pii(f, a));
        }
        for(int i = 0; i < s; i++) {
            int x, _p;
            scanf("%d %d",&x, &_p);
            x--;
            f[x] = i;
            p[i] = _p;
        }
        scanf("%d %d", &c, &d);
        c--; d--;
        f[d] = s;
        compress();
        printf("%d\n", ans());
    }
}

