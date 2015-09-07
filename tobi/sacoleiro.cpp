#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

vector<int> adj[35];
int v[35], memo[35][109][109];
int d[35];

int dp(int c, int t, int d){
    if (t < 0) return INT_MAX/2;
    int &m = memo[c][t][abs(d)];
    if(m != -1) return m;
    m = INT_MAX/2;
    int ans = min(abs(d),dp(c,t-abs(v[c]),d+v[c]));
    int k = adj[c].size();
    for(int i = 0; i < k; i++)
        ans = min(ans,dp(adj[c][i],t,d));
    
    return m = ans;
}

void dfs(int x){
    int k = adj[x].size();
    for(int i = 0; i < k; i++)
        if(d[adj[x][i]] > d[x] + 1){
            d[adj[x][i]] = d[x]+1;
            dfs(adj[x][i]);
        }
}

int main(){
    int n, t;
    scanf("%d %d\n",&n,&t);
    memset(memo,-1,sizeof memo);
    for(int i = 0; i < n; i++)
        d[i] = INT_MAX;
    for(int i = 0; i < n; i++){
        int x,p,k;
        char c;
        scanf("%d %d %c %d",&x,&p,&c,&k);
        if(c == 'A') v[x] = p;
        else v[x] = -p;
        int a;
        for(int j = 0; j < k; j++){
            scanf("%d",&a);
            adj[x].pb(a);
        }
    }
    d[0] = 0;
    dfs(0);
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        if(d[i] != INT_MAX)
            ans = min(ans,dp(0,t-abs(v[i]), v[i]));
    }
    printf("%d\n",ans);
}
