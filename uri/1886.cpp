#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 5*1002;

int t,n,m;
int vis[N], M[N], g[N];
vector<int> adj[N];

void dfs (int no, int k){
    g[no] = k;
    for(int i = 0; i < adj[no].size(); i++)
        if(!g[adj[no][i]]) dfs(adj[no][i],-k);   
}

bool temAumento (int a) {
    for (int i = 0; i < adj[a].size(); i++){
        int b = adj[a][i];
        if(vis[b]) continue;
        vis[b] = 1;
        if (M[b] == -1 || temAumento(M[b])){
            M[a] = b;
            M[b] = a;
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i = 0; i <= n; i++){
            M[i] = -1;
            adj[i].clear();
            g[i] = 0;
        } 
        int a,b;
        for(int i = 0; i < m; i++){
            scanf("%d %d",&a,&b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(1,1);
        int ans = 0;
        while(1){
            int i;
            for(int j = 0; j <= n; j++) vis[j] = 0;
            for(i = 1; i <= n; i++){
                if(g[i] == 1 && M[i] == -1 && temAumento(i)){
                    ans++;
                    break;
                }
            }
            if(i == n+1) break;
        }
        printf("%d\n",n-ans);
    }
}
