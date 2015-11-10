#include <bits/stdc++.h>
#define pb push_back
#define wei first
#define vert second
using namespace std;
typedef pair<int,int> pii;


int n,m,s;
int vis[105];
int d[105];
vector<pii> adj[105];

int cycle (int no, int pai){
    if(vis[no]) return 1;
    vis[no] = 1;
    int ans = 0;
    for(int i = 0; i < adj[no].size(); i++){
        int nx = adj[no][i].vert;
        if(nx == pai) continue;
        ans += cycle(nx,no);
    }
    return ans;
}

void dfs (int no, int pai, int t){
    d[no] = t;
    for(int i = 0; i < adj[no].size(); i++)
        if(adj[no][i].vert != pai)
            dfs(adj[no][i].vert,no,d[no]+adj[no][i].wei);
}

int main(){
    scanf("%d %d %d",&m,&n,&s);
    for(int i = 0; i < n; i++){
        int p,q,r;
        scanf("%d %d %d",&p,&q,&r);
        p--; q--;
        adj[p].pb(pii(r,q));
        adj[q].pb(pii(r,p));
    }
    int arv[105], a = 0;
    for(int i = 0; i < m; i++){
        if(!vis[i]){
            arv[a++] = i;
            if(cycle(i,-1)){
                printf("YES\n");
                return 0;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < a; i++){
        memset(d,-1,sizeof d);
        dfs(arv[i],-1,0);
        int tmp = -1, st;
        for(int j = 0; j < m; j++){
            if(d[j] > tmp){
                tmp = d[j];
                st = j;
            }
        }
        dfs(st,-1,0);
        ans = max(ans, *max_element(d,d+m));
    }
    if(ans >= s) puts("YES");
    else puts("NO");

}
