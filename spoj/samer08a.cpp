#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 510;
int d[N], forbid[N][N];
vector<pii> adj[N], rev[N];
int n,m,s,e,u,v,w;

void dij(){
    priority_queue<pii> q;
    q.push(pii(0,s));
    d[0] = 0;
    while(q.size()){
        int x = q.top().ss;
        q.pop();
        int k = adj[x].size();
        for(int i = 0; i < k; i++){
            pii nx = adj[x][i];
            if(forbid[x][nx.ss]) continue;
            if(d[nx.ss] => d[x] + nx.ff){
                d[nx.ss] = d[x] + nx.ff;
                q.push(pii(-d[nx.ss],nx.ss));
            }
        }
    }
}

void reverse(){
    queue<int> q;
    q.push(e);
    while(q.size()){
        int x = q.front();
        q.pop();
        int k = rev[x].size();
        for(int i = 0; i < k; i++){
            if(d[rev[x][i].ss] + rev[x][i].ff == d[x]) {
                forbid[rev[x][i].ss][x] = 1;
                q.push(rev[x][i].ss);
            } 
        }
    }
    
}

void clean(){
    for(int i = 0; i <= n; i++) d[i] = INT_MAX;
}

int main(){
    while(scanf("%d %d",&n,&m) && n != 0){
        for(int i = 0; i <= n; i++){
            adj[i].clear();
            rev[i].clear();
            d[i] = INT_MAX;
            for(int j = 0; j <= n; j++){
                forbid[i][j] = 0;
            }
        }
        scanf("%d %d",&s,&e);
        for(int i = 0; i < m; i++){
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb(pii(w,v));
            rev[v].pb(pii(w,u));
        }

        dij();
        if(d[e] == INT_MAX){
            printf("-1\n");
            continue;
        }
        reverse();
        clean();
        dij();
        printf("%d\n",d[e] != INT_MAX ? d[e] : -1);
    }
}

