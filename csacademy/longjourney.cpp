#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 100004;
const int modn = 1000000007;

vector<int> adj[N];
int d[N], ina[N];
int n, m, s, a, b;

void mark(int u, int p) {
    ina[u] = 1;
    for(int v : adj[u])
        if(d[v] == p-1)
            mark(v, p-1);
}

int maxi(int u, int p, int at) {
    if(p == 0) return at;
    int ans = 0;
    for(int v : adj[u])
        if(d[v] == p-1)
            ans = max(ans, maxi(v, p-1, at + ina[v]));
    return ans;
}

int solve() {
    queue<int> q;
    for(int i = 0; i < n; i++) d[i] = inf;
    d[s] = 0;
    ina[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    mark(a, d[a]);
    return maxi(b, d[b], 0);
}


int main() {
    scanf("%d %d",&n, &m);
    scanf("%d %d %d",&s,&a,&b);
    s--; a--; b--;
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d",&u, &v);
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    printf("%d\n",solve()-1);
}

