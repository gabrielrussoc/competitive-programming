#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
int n,m,a,b,k,g;
int gp[1005], acg[1005];
int wei[1005][1005];
int d[1005];
vector<int> adj[1005];

int bb(int x){
    int lo = 0, hi = g-1;
    while(lo != hi){
        int mid = (lo+hi+1)/2;
        if(acg[mid] <= x) lo = mid;
        else hi = mid-1;
    }
    if(acg[lo] <= x) return lo;
    else return g;
}

void dij(){
    priority_queue<pii> q;
    d[a] = k;
    q.push(pii(-k,a));
    while(q.size()){
        int at = q.top().ss;
        q.pop();
        for(int i = 0; i < adj[at].size(); i++){
            int nxt = adj[at][i];
            int x = bb(d[at]);
            int xab = 0;
            if(x != g){
                if((gp[x] == at && gp[x+1] == nxt) || (gp[x+1] == at && gp[x] == nxt))
                   xab = wei[at][nxt] - (d[at]-acg[x]); 
            }
            if(d[nxt] > d[at] + wei[nxt][at] + xab){
                d[nxt] = d[at] + wei[nxt][at] + xab;
                q.push(pii(-d[nxt],nxt));
            }
        }
    }
}

void fill (){
    for(int i = 0; i <= n; i++)
        d[i] = INT_MAX;
}

int main(){

    scanf("%d %d",&n,&m);
    scanf("%d %d %d %d",&a,&b,&k,&g);
    fill();    
    for(int i = 0; i < g; i++)
        scanf("%d",gp+i);
    
    for(int i = 0; i < m; i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        adj[x].pb(y);
        adj[y].pb(x);
        wei[x][y] = wei[y][x] = w;
    }

    acg[0] = 0;
    for(int i = 1; i < g; i++)
        acg[i] = acg[i-1] + wei[gp[i]][gp[i-1]];


    dij();
    printf("%d\n",d[b]-k);

}
