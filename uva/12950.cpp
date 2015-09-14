#include <bits/stdc++.h>
#define ff first
#define ss second
#define pii pair<int,int>
#define N 10004
#define pb push_back
#define mp make_pair

using namespace std;

vector<pii> adj[2*N];
int d[2*N];

void dij(){
    d[1] = 0;
    priority_queue<pii> q;
    q.push(mp(0,1));
    while(q.size()){
        pii at = q.top();
        q.pop();
        int k = adj[at.ss].size();
        for(int i = 0; i < k; i++){
            pii nxt = adj[at.ss][i];
            int w = nxt.ff;
            if(d[nxt.ss] > d[at.ss] + w){
                d[nxt.ss] = d[at.ss]+w;
                q.push(mp(-d[nxt.ss],nxt.ss));
            }
        } 
    }
}

int main(){
    int c,v;
    while(scanf("%d %d",&c,&v) != EOF){
        for(int i = 1; i <= 2*c; i++){
            d[i] = INT_MAX;
            adj[i].clear();
        }
        for(int i = 0; i < v; i++){
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);
            adj[a].pb(mp(w,c+b));
            adj[a+c].pb(mp(w,b));
            adj[b].pb(mp(w,a+c));
            adj[b+c].pb(mp(w,a));
        }
        dij();
        printf("%d\n",d[c] != INT_MAX ? d[c] : -1);
    }
}
