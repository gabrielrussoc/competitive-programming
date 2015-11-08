#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define vert second
#define wei first
using namespace std;
typedef pair<int,int> pii;

vector<pii> adj[1005];
int d[1005];

int mod (int a, int b){
    if(a%b == 0) return b;
    return a%b;
}

void solve(){
    priority_queue<pii> q;
    d[1] = 0;
    q.push(pii(0,1));
    while(q.size()){
        int at = q.top().vert;
        q.pop();
        for(int i = 0; i < adj[at].size(); i++){
            pii nxt = adj[at][i];
            if(d[nxt.vert] > d[at] + nxt.wei + 2*nxt.wei - mod(d[at],2*nxt.wei)){
                d[nxt.vert] = d[at] + nxt.wei + 2*nxt.wei - mod(d[at],2*nxt.wei);
                q.push(pii(-d[nxt.vert],nxt.vert));
            } 
        }
    }
}

int main(){
    //freopen("liftovi.in","r",stdin);
    //freopen("liftovi.out","w",stdout); 
    int n, k;
    scanf("%d %d",&k,&n);
    for(int i = 0; i <= k; i++){
        adj[i].clear();
        d[i] = INT_MAX;
    }
    for(int i = 0; i < n; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].pb(mp(b-a,b));
        adj[b].pb(mp(b-a,a));
    }
    solve();
    printf("%d\n",5*d[k]);

}
