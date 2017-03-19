#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 112345;

int t, n, ti;
int d[N], f[N], dep[N], ans[N], tree[4*N];
vector<int> adj[N];
pii eve[2*N];

int query(int fl, int fr, int k = 1, int l = 0, int r = n-1) {
    if(l > fr || r < fl) return 0;
    if(l >= fl && r <= fr) return tree[k];
    int m = (l+r)/2;
    return max(query(fl, fr, 2*k, l, m), query(fl, fr, 2*k+1, m+1, r));
}

void update(int i, int val, int k = 1, int l = 0, int r = n-1) {
    if(l == r) {
        tree[k] = val;
        return;
    }
    int m = (l+r)/2;
    if(i <= m) update(i, val, 2*k, l, m);
    else update(i, val, 2*k+1, m+1, r);
    tree[k] = max(tree[2*k], tree[2*k+1]);
}

int dfs(int u, int p) {
    dep[u] = p;
    d[u] = ti++;
    for(int v : adj[u])
        dfs(v, p+1);
    f[u] = ti;
}

int main() {
    scanf("%d",&t);
    while(t--) {
        ti = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) adj[i].clear();
        memset(tree, 0, sizeof tree);
        for(int i = 0; i < n; i++) {
            int p, a, b;
            scanf("%d %d %d",&p, &a, &b);
            if(p != -1) adj[p].pb(i);
            int u = i+1;
            eve[2*i] = pii(a, -u);
            eve[2*i+1] = pii(b, u);
        }
        dfs(0, 0);
        sort(eve, eve+2*n);
        for(int i = 0; i < 2*n; i++) {
            int u = abs(eve[i].second) - 1;
            int die = eve[i].second > 0;
            if(die) ans[u] = query(d[u], f[u]-1) - dep[u];
            else update(d[u], dep[u]);
        }
        for(int i = 0; i < n; i++) printf("%d ", ans[i]);
        putchar('\n');
    }
}

