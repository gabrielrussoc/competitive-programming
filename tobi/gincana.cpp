#include <cstdio>
#include <vector>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

using namespace std;

vector<int> adj[1009];
int p[1006];

int dfs(int i){
    if(p[i]) return 0;
    p[i] = 1;
    int k = adj[i].size();
    int ans = 1;
    for(int j = 0; j < k; j++)
        if(!p[adj[i][j]]) ans += dfs(adj[i][j]); 

    return ans;
}

int main(){

    for(int i = 0; i < 1006; i++)
        p[i] = 0;

    int n,m;
    scanf("%d %d",&n,&m);

    for(int i = 0; i < m; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        //printf("%d\n",dfs(i));
        if(dfs(i)) ans++;
    }
    
    printf("%d\n",ans);
}
