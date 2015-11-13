#include <bits/stdc++.h>
#define pb push_back
#define wei first
#define vert second
using namespace std;
typedef pair<int,int> pii;

const int N = 100005;
int g[N], go[N], ret[N], forbid[N];
vector<pii> adj[N];
int cont = 0;

void del(int no){
    forbid[no] = 1;
    int pai;
    for(int i = 0; i < adj[no].size(); i++)
        if(!forbid[adj[no][i].vert]) pai = adj[no][i].vert;
    g[pai]--;
    if(g[pai] == 1 && !go[pai] && pai != 1) del(pai); 
}

int pre(int no, int pai){
    if(g[no] == 1 && no != 1) return 0;
    ret[no] = 0;
    for(int i = 0; i < adj[no].size(); i++)
        if(adj[no][i].vert != pai && !forbid[adj[no][i].vert])
            ret[no] += pre(adj[no][i].vert, no) + adj[no][i].wei;
    return ret[no];
}

int solve(int no, int pai){
    if(g[no] == 1 && no != 1) return 0;
    int ans = INT_MAX;
    for(int i = 0; i < adj[no].size(); i++){
        if(adj[no][i].vert != pai && !forbid[adj[no][i].vert])
            ans = min(ans,ret[no] - ret[adj[no][i].vert] -adj[no][i].wei+ solve(adj[no][i].vert,no));
    }
    return ans;
}

int main(){
    int n,f,a,b,w;
    scanf("%d %d",&n,&f);
    for(int i = 0; i < n-1; i++){
        scanf("%d %d %d",&a,&b,&w);
        adj[a].pb(pii(w,b));
        adj[b].pb(pii(w,a));
        g[a]++, g[b]++;
    }
    for(int i = 0; i < f; i++){
        scanf("%d",&a);
        go[a] = 1;
    }
    for(int i = 2; i <= n; i++)
        if(g[i] == 1 && !go[i] && !forbid[i]) del (i);
    
    int foo;
    foo = pre(1,-1);
    foo = solve(1,-1);
    printf("%d\n",foo);

}
