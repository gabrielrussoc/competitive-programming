#include <bits/stdc++.h>
#define pb push_back
#define wei first
#define vert second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 5001;
vector<pii> adj[N];
int n, m, t;
int memo[N][N];

int dp (int u, int lf) {
    if(lf == 0) {
        if(u == n-1) return 0;
        return t+1;
    }
    int &me = memo[u][lf];
    if(me != -1) return me;
    me = t+1;
    for(pii a : adj[u]) {
        int w = a.wei;
        int v = a.vert;
        me = min(me, dp(v,lf-1) + w);
    }
    return me;
}

void build (int u, int lf){
    if(lf == 0 || u == n-1) return;
    int loc = t+1;
    int nv;
    for(pii a : adj[u]) {
        int w = a.wei;
        int v = a.vert;
        if(dp(v,lf-1) + w < loc) {
            loc = dp(v,lf-1) + w;
            nv = v;   
        }
    }
    printf("%d ",u+1);
    build(nv,lf-1);
}

int main() {
    scanf("%d %d %d",&n,&m,&t);
    memset(memo,-1,sizeof memo);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d",&u,&v,&w); u--; v--;
        adj[u].pb(pii(w,v));
    }
    int q;
    for(q = n; q >= 0; q--) if(dp(0,q) <= t) break;
    printf("%d\n",q+1);
    build(0, q);
    printf("%d\n",n);
}

