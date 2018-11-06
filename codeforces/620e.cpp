#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 400005;

int n;
int c[N];
int tempo = 0;
int ord[N], sz[N], fst[N];
ll tree[4*N]; 
int lazy[4*N];

vector<int> adj[N];

int dfs(int u, int p = -1) {
    fst[u] = tempo;
    ord[tempo++] = u;
    int loc = 1;
    for(int v : adj[u])
        if(v != p)
            loc += dfs(v, u);
    sz[u] = loc;
    return loc;
}

void init(int k = 1, int l = 0, int r = n-1) {
    if(l == r) {
        tree[k] = 1ll<<c[ord[l]];
        return;
    }
    int m = (l+r)/2;
    init(2*k, l, m);
    init(2*k+1, m+1, r);
    tree[k] = tree[2*k] | tree[2*k+1];
}

void unlazy(int k, bool leaf) {
    if(!lazy[k]) return;
    if(!leaf)
        lazy[2*k] = lazy[2*k+1] = lazy[k];
    tree[k] = 1ll<<lazy[k];
    lazy[k] = 0;
}

void update(int fl, int fr, int val, int k = 1, int l = 0, int r = n-1) {
    unlazy(k, l == r);
    if(l >= fl && r <= fr) {
        lazy[k] = val;
        unlazy(k, l == r);
        return;
    }
    if(l > fr || r < fl) return;
    int m = (l+r)/2;
    update(fl, fr, val, 2*k, l, m);
    update(fl, fr, val, 2*k+1, m+1, r);
    tree[k] = tree[2*k] | tree[2*k+1];
}

ll query(int fl, int fr, int k = 1, int l = 0, int r = n-1) {
    unlazy(k, l == r);
    if(l >= fl && r <= fr) return tree[k];
    if(l > fr || r < fl) return 0;
    int m = (l+r)/2;
    return query(fl, fr, 2*k, l, m) | query(fl, fr, 2*k+1, m+1, r);
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", c+i);
    for(int i = 0; i < n-1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1);
    init();
    while(m--) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            int v, nc;
            scanf("%d %d", &v, &nc);
            update(fst[v], fst[v] + sz[v]-1, nc);
        } else {
            int v;
            scanf("%d", &v);
            printf("%d\n", __builtin_popcountll(query(fst[v], fst[v]+sz[v]-1)));
        }
    }
}


