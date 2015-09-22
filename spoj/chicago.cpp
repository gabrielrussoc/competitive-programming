#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
const int N = 105;
typedef pair<int,double> pii;


int n,m;
vector<pii> adj[N];
double d[N];

void solve(){
    priority_queue<pii> pq;
    d[1] = 1;
    pq.push(mp(-1,1));
    while(pq.size()){
        int x;
        x = pq.top().second;
        pq.pop();
        int k = adj[x].size();
        for(int i = 0; i < k; i++){
            if(d[adj[x][i].ff] < d[x] * adj[x][i].ss){
                d[adj[x][i].ff] = d[x] * adj[x][i].ss;
                pq.push(mp(-d[adj[x][i].ff], adj[x][i].ff));
            }
        }
    }
}

int main(){
    while(scanf("%d %d",&n,&m) && n != 0){
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
            d[i] = INT_MIN;
        }
        for(int i = 0; i < m; i++){
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);
            adj[a].pb(mp(b,w/100.0));
            adj[b].pb(mp(a,w/100.0));
        }
        solve();
        printf("%.6lf percent\n",d[n]*100);
    }
}