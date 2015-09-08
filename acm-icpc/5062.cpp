#include <cstdio>
#include <vector>
#define pb push_back

using namespace std;

bool seen[2508];
vector<int> adj[2508];
int ans,n,m,a,b;

void clean (int n){
    for(int i = 1; i <= n; i++){
        seen[i] = false;
    }
}   

void adjclean (int n){
    for(int i = 1; i <= n; i++){
        adj[i].clear();
    }
}   

void dfs(int j){
    if(seen[j]) return;
    ans++;
    seen[j] = true;
    int k = adj[j].size();
    for(int i = 0; i < k; i++)
        dfs(adj[j][i]);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        adjclean(n);
        ans = 0;
        for(int i = 0; i < m; i++){
            scanf("%d %d",&a,&b);
            adj[a].pb(b);
        }
        for(int i = 1; i <= n; i++){
            clean(n);
            dfs(i);
        }
        printf("%d\n",ans-n);
    }
}
