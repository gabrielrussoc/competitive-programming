#include <cstdio>
#include <climits>
#include <vector>
#define pb push_back

using namespace std;

vector<int> adj[10004];
bool seen[10004];
int ini = 1;
int ult;

void dfs(int k){
    ult = k;
    if(seen[k]) return;
    seen[k] = true;
    dfs(adj[k][0]);
}



int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int a,b;
        seen[i+1] = false;
        scanf("%d %d",&a,&b);
        adj[a].pb(b);
    }
    for(int i = 1; i <= n; i++)
        if(adj[i].size() != 1){
            printf("N\n");
            return 0;
        }
    dfs(ini);
    for(int i = 1; i <= n; i++)
        if(!seen[i]){
            printf("N\n");
            return 0;
        }
    printf("%c\n",ini == ult ? 'S' : 'N');

}
