#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
const int N = 256;

int n,m,c,k,a,b,w;
vector<pii> adj[N];
int d[N], W[N][N];
int ans[N];

void solve(){
    priority_queue<pii> pq;
    pq.push(mp(0,k));
    d[k] = 0;
    while(pq.size()){
        int x = pq.top().second;
        int y = adj[x].size();
        pq.pop();
        for(int i = 0; i < y; i++){
            int nx = adj[x][i].ff, wei = adj[x][i].ss;
            if(d[nx] > d[x] + wei){
                d[nx] = d[x] + wei;
                pq.push(mp(-d[nx],nx));
                ans[nx] = x;
            }
        }
    }
}



int main(){
    while(scanf("%d %d %d %d",&n,&m,&c,&k) && n != 0){
        for(int i = 0; i < n; i++){
            adj[i].clear();
            d[i] = INT_MAX;
            ans[i] = -1;
        }
        for(int i = 0; i < m; i++){
            scanf("%d %d %d",&a,&b,&w);
            adj[a].pb(mp(b,w));
            W[a][b] = W[b][a] = w;
        }
        solve();
        int p = c-1;
        int j, resp = 0;
        while(ans[p] != -1){
            if(ans[p] < c) j = ans[p];
            p = ans[p];
        }
        for(int i = j; i < c-1; i++){
            resp += W[i][i+1];
        }
        printf("%d\n",d[c-1]);

    }
}