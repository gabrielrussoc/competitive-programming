#include <bits/stdc++.h>
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
int cap[M], flow[M], vis[N];
int n, m, es = 2, s, t;

int dfs(int u, int mini) {
    vis[u] = 1;
    if(u == t) return mini;
    for(int e = head[u]; e; e = nx[e]) {
        int v = to[e];
        if(!vis[v] && cap[e] - flow[e]) {
            int k = dfs(v, min (cap[e]-flow[e], mini));
            if(k != inf){
                flow[e] += k;
                flow[e^1] -= k;
                return k;
            }
        }
    }
    return inf;
}

int max_flow(){
    int mf = 0;
    while(true) {
        memset(vis,0,sizeof vis);
        int k = dfs(s,inf);
        if(k == inf) break;
        mf += k;
    }
    return mf;
}


int main() {
    int tc = 1;
    while(scanf("%d",&n) && n) {
        for(int i = 0; i < n ; i++) head[i]=0;
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

