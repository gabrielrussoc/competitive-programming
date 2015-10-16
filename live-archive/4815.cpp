#include <bits/stdc++.h>
using namespace std;

set<int> adj[200008];
map<int,int> m;
int vis[200008],k,w;
bool ans;
int cont;

void dfs (int no, int p){
set<int>::iterator it;
    if(p != -1 && vis[no]){
        ans = false;
        return;
    }
    if(vis[no]) return;
    vis[no] = 1;
    cont++;
    for(it = adj[no].begin(); it != adj[no].end(); it++){
        if(*it != p) dfs(*it,no);
    }
}


int main(){
    while(scanf("%d %d",&k,&w) && k != 0){
        int g = 1;
        m.clear();
        int a,b;
        for(int i = 0; i < w; i++){
            scanf("%d %d",&a,&b);
            if(!m[a]) {
                m[a] = g++;
                adj[m[a]].clear();
            }
            if(!m[b]){
                m[b] = g++;
                adj[m[b]].clear();
            }
            a = m[a]; b = m[b];
            adj[a].insert(b);
            adj[b].insert(a);
        }
        ans = true;
        for(int i = 1; i < g; i++){
            vis[i] = 0;
            if(adj[i].size() > 2){
                ans = false; 
            }
        }
        if(!ans){
            puts("N");
            continue;
        }
        for(int i = 1; i < g; i++){
            cont = 0;
            dfs(i,-1);
            if(cont == k){
               ans = true;
               break;
            }
            if(!ans){
                puts("N");
                break;
            }
        }
        if(ans)
            puts("Y");
    }
}
