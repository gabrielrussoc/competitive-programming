#include <cstdio>
#include <vector>
#define pb push_back

using namespace std;
const int N = 10004;

vector<int> adj[N];
bool jose = true;

int dfs(int node){
    int k = adj[node].size();
    int ans = 1, last, at;
    for(int i = 0; i < k; i++){
        if(!i) last = dfs(adj[node][i]);
        else{
            at = dfs(adj[node][i]);
            if(at != last) jose = false;
            last = at;
        }
        ans += last;
    }
    return ans;
}

int main(){
    int n;
    scanf("%d",&n);
    int a,b;
    for(int i = 0; i < n; i++){
        scanf("%d %d",&a,&b);
        adj[b].pb(a);
    }
    dfs(0);
    if(jose) printf("bem\n");
    else printf("mal\n");
}
