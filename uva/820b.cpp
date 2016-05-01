#include <bits/stdc++.h>
#define DEBUG(args...) fprintf(stderr, args)
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
const int M = 2*N*N;
const int modn = 1000000007;

int head[N], nx[M], to[M];
int cap[M], flow[M], vis[N], d[N], p[N];
int n, m, es, s, t;

bool bfs() {
    for(int i = 0; i < n; i++) d[i] = inf;
    queue<int> q;
    d[s] = 0;
    p[s] = -1;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int e = head[u]; e; e = nx[e]) {
            if(cap[e] - flow[e] <= 0) continue;
            int v = to[e];
            if(d[v] > d[u] + 1){
                p[v] = e;
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t] != inf;
}

int max_flow(){
    int mf = 0;
    while(bfs()) {
        int u = t;
        int k = inf;
        while(p[u] != -1) {
            int e = p[u];
            k = min(k, cap[e] - flow[e]);
            u = to[e^1];
        }
        u = t;
        while(p[u] != -1) {
            int e = p[u];
            flow[e] += k;
            flow[e^1] -= k;
            u = to[e^1];
        }
        mf += k;
    }
    return mf;
}


int main() {
    int tc = 1;
    while(scanf("%d",&n) && n) {
        es = 2;
        for(int i = 0; i < n; i++) head[i] = 0;
        scanf("%d %d %d",&s,&t,&m); s--; t--;
        int u, v, c;
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d",&u, &v, &c);
            u--; v--;
            to[es] = v; nx[es] = head[u]; head[u] = es; cap[es] = c; flow[es++] = 0;
            to[es] = u; nx[es] = head[v]; head[v] = es; cap[es] = c; flow[es++] = 0;
        }
        printf("Network %d\n",tc++);
        printf("The bandwidth is %d.\n\n",max_flow());
    }
}

