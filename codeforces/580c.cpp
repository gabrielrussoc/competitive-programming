#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define modn 1000000007
using namespace std;
typedef long long ll;
const int N = 100005;

vector<int> adj[N];
int cat[N];
int n,m, ans = 0,a,b;

void dfs (int no, int dad, int gato, int pega, int mgato){
    int k = adj[no].size();
    if(k == 1 && no != 1){
        if(mgato <= m) ans++;
        return;
    }

    for(int i = 0; i < k; i++){
        int nxt = adj[no][i];
        if(cat[nxt] && nxt != dad){
            if(pega)
                dfs(nxt,no,gato+1,1, max(gato+1,mgato));
            else
                dfs(nxt,no,1,1,max(1,mgato));
        }
        else if(nxt != dad)
            dfs(nxt,no,0,0,mgato);
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++)
        scanf("%d",&cat[i]); 
    for(int i = 0; i < n-1; i++){
        scanf("%d %d",&a,&b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    if(cat[1])
        dfs(1,0,1,1,1);
    else
        dfs(1,0,0,0,0);
    printf("%d\n",ans);
}
