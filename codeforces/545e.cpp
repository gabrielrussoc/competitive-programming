#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;

struct edge {
    int to;
    ll w;
    int num;
    edge(){}
    edge(int a, ll b, int c) : to(a), w(b), num(c) {}
};
const int N = 300005;
const ll inf = LLONG_MAX;
int n,m,u,v;
ll w;
vector<edge> adj[N];
ll d[N];
pil r[N];

void solve (int f){
    priority_queue<pli> q;
    d[f] = 0;
    q.push(pli(0,f));
    while(q.size()){
        int at = q.top().ss;
        q.pop();
        int k = adj[at].size();
        for(int i = 0; i < k; i++){
            int nx = adj[at][i].to;
            ll wei = adj[at][i].w;
            if(d[nx] > d[at] + wei){
                d[nx] = d[at] + wei;
                if(r[nx].ss > wei){
                    r[nx].ff = adj[at][i].num;
                    r[nx].ss = wei;
                }
                q.push(pli(-d[nx],nx));
            }
            else if(d[nx] == d[at] + wei){
                if(r[nx].ss > wei){
                    r[nx].ff = adj[at][i].num;
                    r[nx].ss = wei;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i <= n; i++){
        d[i] = inf;
        r[i].ss = inf;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d %I64d",&u,&v,&w);
        adj[u].pb(edge(v,w,i+1));
        adj[v].pb(edge(u,w,i+1));
    }
    scanf("%d",&u);
    solve(u);
    ll tot = 0;
    for(int i = 1; i <= n; i++)
        if(i != u) tot += r[i].ss;
    cout << tot << endl;
    for(int i = 1; i <= n; i++)
        if(i != u) cout << r[i].ff << " ";
    cout << endl;


}
