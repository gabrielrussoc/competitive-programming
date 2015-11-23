#include <bits/stdc++.h>
#define wei first
#define vert second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
vector<pii> adj[60];

char foo, bar;
int p, st, end;
int n;
int d[60];

int f(char c){
    if(isupper(c)) return c-'A'+26;
    return c-'a';
}

int peso(int t, int w){
    if(t) return 1;
    return (w+19)/20;
}

void djalma (int k){
    priority_queue<pii> q;
    d[st] = k;
    q.push(pii(k,st));
    while(q.size()){
        int at = q.top().vert;
        q.pop();
        for(int i = 0; i < adj[at].size(); i++){
            int nx = adj[at][i].vert;
            int w = peso(adj[at][i].wei,d[at]);
            if(d[nx] < d[at] - w){
                d[nx] = d[at] - w;
                q.push(pii(d[nx],nx));
            }
        }
    }
}


int main(){
    int tc = 1;
    while(scanf("%d",&n) && n != -1){
        for(int i = 0; i < 52; i++) adj[i].clear();
        for(int i = 0; i < n; i++){
            int u,v;
            scanf(" %c %c",&foo,&bar);
            u = f(foo);
            v = f(bar);
            if(v > 25) adj[u].pb(pii(0,v));
            else adj[u].pb(pii(1,v));
            if(u > 25) adj[v].pb(pii(0,u));
            else adj[v].pb(pii(1,u));
        }
        scanf("%d %c %c",&p,&foo,&bar);
        st = f(foo);
        end = f(bar);
        int lo = 1, hi = INT_MAX;
        while(lo != hi) {
            int mid = lo + (hi-lo)/2;
            for(int i = 0; i < 52; i++) d[i] = INT_MIN;
            djalma(mid);
            if(d[end] >= p) hi = mid;
            else lo = mid+1;
        }
        printf("Case %d: %d\n",tc++,lo);
    }
}
