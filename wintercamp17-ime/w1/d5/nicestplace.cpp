#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define GNU __gnu_pbds
#define pb push_back
#define ff first
using namespace std;
typedef pair<int, int> pii;
namespace GNU { typedef tree<pii, null_type, greater<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; }
typedef long long ll;
using GNU::ordered_set;

const int N = 500005;
int g = 0;

struct edge {
    int u, v, w;
    edge () {}
    edge (int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const edge &o) const {
        return w < o.w;
    }
} edges[N];

struct qry {
    int p, d, k, i;
    qry () {}
    qry (int p, int d, int k, int i) : p(p), d(d), k(k), i(i) {}
    bool operator<(const qry &o) const {
        return d < o.d;
    }
} query[N];


//(int) *s.find_by_order(a)
//(int) s.order_of_key(a)

int n, m, q;
int val[N];
vector<edge> adj[N];
int uf[N], wf[N], ans[N];
ordered_set v[N];

int find(int p) {
    if(p == uf[p]) return p;
    return uf[p] = find(uf[p]);
}

void show_set(int p) {
    for(pii x : v[p])
        printf("%d ", x.ff);
    puts("\n----");
}

void join(int p, int q) {
    p = find(p);
    q = find(q);
    if(p == q) return;
    if(wf[p] > wf[q]) swap(p, q);
    for(pii x : v[p])
        v[q].insert(pii(x.ff, g++));
    uf[p] = q;
    wf[q] += wf[p];
}

int main() {
    scanf("%d %d %d", &n, &m, &q); 
    for(int i = 0; i < n; i++) {
        scanf("%d", val+i);
        uf[i] = i;
        v[i].insert(pii(val[i], g++));
        wf[i] = 1;
    }
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        edges[i] = edge(u, v, w);
        adj[u].pb(edge(u,v,w));
        adj[v].pb(edge(v,u,w));
    }
    sort(edges, edges+m);
    for(int i = 0; i < q; i++) {
        int p, d, k;
        scanf("%d %d %d", &p, &d, &k); p--; k--;
        query[i] = qry(p, d, k, i);
    }
    sort(query, query+q);
    int j = 0;
    for(int i = 0; i < q; i++) {
        int p, d, k;
        p = query[i].p;
        d = query[i].d;
        k = query[i].k;
        while(j < m && edges[j].w <= d) {
            join(edges[j].u, edges[j].v);
            j++;
        }
        p = find(p);
        if(end(v[p]) == v[p].find_by_order(k)) 
            ans[query[i].i] = -1;
        else 
            ans[query[i].i] = (v[p].find_by_order(k))->ff;
    }
    for(int i = 0; i < q; i++) printf("%d\n", ans[i]);
}

