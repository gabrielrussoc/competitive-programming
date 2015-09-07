#include <cstdio>
#include <vector>
#define pb push_back

using namespace std;

vector<int> adj[105];
bool seen[105];


void clean(int n){
    for(int i = 0; i < n; i++)
        adj[i].clear();
    for(int i = 0; i < n; i++)
        seen[i] = false;
}

void dfs(int j){
    if (seen[j]) return;
    seen[j] = true;
    int k = adj[j].size();
    for(int i = 0; i < k; i++)
        dfs(adj[j][i]);

}

int main(){
    int tc = 1;
    int e,l;
    while(scanf("%d %d",&e,&l) && e != 0 && l != 0){
        clean(e);
        for(int i = 0; i < l; i++){
            int a,b;
            scanf("%d %d",&a,&b);
            a--, b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(0);
        bool ans = true;
        for(int i = 0; i < e; i++)
            if(!seen[i]) ans = false;       
        printf("Teste %d\n",tc++);
        if(ans) printf("normal\n\n");
        else printf("falha\n\n");
    } 
}
