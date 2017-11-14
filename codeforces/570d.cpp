#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 500005;

struct qry {
    int v, h, i;
    qry(){}
    qry(int v, int h, int i) : v(v), h(h), i(i) {}
    bool operator<(const qry &o) const {
        return h < o.h;
    }
} q[N];

int ans[N], pre[N], pos[N], let[N], tree[4*N], tim, dep[N], ord[N];
int n, m;
vector<int> adj[N];

void dfs(int u, int d = 1) {
    dep[u] = d;
    pre[u] = tim++;
    for(int v : adj[u]) 
        dfs(v, d+1);
    pos[u] = tim;
}

void upd(int i, int val, int k = 1, int l = 0, int r = n-1) {
    if(l == r) {
        tree[k] ^= (1<<val);
        return;
    } 
    int mid = (l + r) / 2;
    if(i <= mid) upd(i, val, 2*k, l, mid);
    else upd(i, val, 2*k+1, mid+1, r);
    tree[k] = tree[2*k] ^ tree[2*k+1]; 
}

int query(int fl, int fr, int k = 1, int l = 0, int r = n-1) {
    if(l >= fl && r <= fr) return tree[k];
    if(l > fr || r < fl) return 0;
    int mid = (l + r) / 2;
    return query(fl, fr, 2*k, l, mid) ^ query(fl, fr, 2*k+1, mid+1, r);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n-1; i++) {
        int p;
        scanf("%d", &p); p--;
        adj[p].pb(i+1);
    }
    for(int i = 0; i < n; i++) {
        ord[i] = i;
        char c;
        scanf(" %c", &c);
        let[i] = c-'a';
    }
    for(int i = 0; i < m; i++) {
        int v, h;
        scanf("%d %d", &v, &h); v--;
        q[i] = qry(v, h, i);
    }
    sort(q, q+m);
    dfs(0);
    sort(ord, ord+n, [&](int i, int j) { return dep[i] < dep[j]; });
    int i = 0, j = 1;
    upd(i, let[ord[i]]);
    for(int k = 0; k < m; k++) {
        int u = q[k].v;
        int d = q[k].h;
        while(j < n && dep[ord[j]] <= d) {
            upd(pre[ord[j]], let[ord[j]]);
            j++;
        }
        while(i < n && dep[ord[i]] < d) {
            upd(pre[ord[i]], let[ord[i]]);
            i++;
        } 
        ans[q[k].i] = __builtin_popcount(query(pre[u], pos[u]-1)) <= 1;
    }
    for(int i = 0; i < m; i++) printf("%s\n", ans[i] ? "Yes" : "No");
}

