#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N = 200005;

ll p[N];
vector<pii> adj[N];
pii pai[N];
int uf[N], pf[N];
pii edge[N];

int find(int i){
    if (i == uf[i]) return i;
    return uf[i] = find(uf[i]);
}

void join(int i, int j){
    i = find(i); j = find(j);
    if(i == j) return;
    if(pf[i] < pf[j]) swap(i,j);
    uf[i] = j;
}


int n,m;

void dfs(int no, int d, int k){
    pai[no].first = d;
    pf[no] = k;
    for(int i = 0; i < adj[no].size(); i++)
        if(adj[no][i].first != d) {
            pai[adj[no][i].first].second = adj[no][i].second;
            dfs(adj[no][i].first,no,k+1);
            if(p[adj[no][i].second] == 1) join(no,adj[no][i].first);
        }
}

ll solve(int a, int b, ll y){
    a = find(a); b = find(b);
    while(a != b && y){
        if(pf[a] > pf[b]){
            y /= p[pai[a].second];
            a = find(pai[a].first);
        }
        else {
            y /= p[pai[b].second];
            b = find(pai[b].first);
        }
    }
    return y;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0; i <= n; i++) {
        uf[i] = i;
    }
    for(int i = 0; i < n-1; i++){
        int a,b;
        ll c;
        scanf("%d %d %I64d",&a,&b,&c);
        adj[a].pb(pii(b,i));
        adj[b].pb(pii(a,i));
        edge[i] = pii(a,b);
        p[i] = c;
    }
    dfs(1,1,0);
    for(int i = 0; i < m; i++){
        int t,a,b,pp;
        ll y,c;
        scanf("%d",&t);
        if(t == 1){
            scanf("%d %d %I64d",&a,&b,&y);
            printf("%I64d\n",solve(a,b,y));
        }
        else {
            scanf("%d %I64d",&pp,&c);
            p[--pp] = c;
            if(c == 1) join(edge[pp].first,edge[pp].second);
        }
        
    }
}
