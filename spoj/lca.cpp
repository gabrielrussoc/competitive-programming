#include <bits/stdc++.h>
using namespace std;

typedef int node;
typedef int edge;

const int N = 1004;

int es;
int l[N][20], dep[N];
int head[N], to[N*N], nx[N*N], g[N];

void dfs (node u, node p, int d) {
    l[u][0] = p; dep[u] = d;
    for (int i = 1; i < 20; i++)
        l[u][i] = l[l[u][i-1]][i-1];
    for (edge e = head[u]; e; e = nx[e]){
        node v = to[e];
        if (v != p) dfs(v, u, d + 1);
    }
}

node lca (node u, node v) {
    if (dep[u] > dep[v]) swap(u,v);
    if (dep[u] < dep[v]) {
        for (int i = 19; i >= 0; i--)
            if(dep[l[v][i]] >= dep[u])
                v = l[v][i];
    }
    if (u == v) return v;
    for (int i = 19; i >= 0; i--)
        if(l[v][i] != l[u][i])
           v = l[v][i], u = l[u][i];
   return l[v][0]; 
}

int main (){
    int t,q,v,u,m,n;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d",&n);
        es = 2;
        memset(head,0,sizeof head);
        memset(g,0,sizeof g);
        for(int i = 1; i <= n; i++){
            scanf("%d",&m);
            for(int j = 0; j < m; j++){
                scanf("%d",&v);
                g[v]++;
                to[es] = v; nx[es] = head[i]; head[i] = es++;
            }
        }
        for(int i = 1; i <= n; i++) if(!g[i]) {dfs(i,i,0); break;}
        scanf("%d",&q);
        printf("Case %d:\n",tc);
        while(q--){
            scanf("%d %d",&u,&v);
            printf("%d\n",lca(u,v));
        }
    }
}
