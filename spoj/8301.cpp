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
int d[N];

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
            }
        }
    }
}

int main(){
    while(scanf("%d %d %d %d",&n,&m,&c,&k) && n != 0){
        for(int i = 0; i < n; i++){
            adj[i].clear();
            d[i] = INT_MAX;
        }
        for(int i = 0; i < m; i++){
            scanf("%d %d %d",&a,&b,&w);
            if(a > b) swap(a,b);
            if(a >= c || b == a+1)
                adj[a].pb(mp(b,w));
            if(b >= c)
                adj[b].pb(mp(a,w));
        }
        solve();
        
        printf("%d\n",d[c-1]);

    }
}
