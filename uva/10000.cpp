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
const int N = 104;
const int modn = 1000000007;

int n,s;
int es, head[N], nx[N*N], to[N*N], gr[N], d[N], topo[N], ps, st[N], ts;

void toposort() {
    ts = 0;
    for(int i = 0; i < n; i++) if(gr[i] == 0) st[ps++] = i;
    while (ps) {
        int u = st[--ps];
        topo[ts++] = u;
        for (int e = head[u]; e; e = nx[e]){
            int v = to[e];
            gr[v]--;
            if(gr[v] == 0) st[ps++] = v;
        }
    }
}

void solve() {
    d[s] = 0;
    for(int i = 0; i < ts; i++) {
        int u = topo[i];
        if(d[u] != -inf) {
            for(int e = head[u]; e; e = nx[e]){
                int v = to[e];
                if(d[v] < d[u] + 1) d[v] = d[u]+1;
            }
        }
    }
}


int main() {
    int tc=1;
    while(scanf("%d",&n) && n) {
        es = 2;
        for(int i = 0; i < n; i++) gr[i] = head[i] = 0, d[i] = -inf;
        scanf("%d",&s);
        s--;
        int p, q;
        while(scanf("%d %d",&p,&q) && p && q) {
            p--; q--;
            to[es] = q; nx[es] = head[p]; head[p] = es++;
            gr[q]++;
        } 
        toposort();
        solve();
        int maxi = 0, ans = 0;
        for (int i = 0; i < n; i++) if(d[i] > maxi) maxi = d[i], ans = i;
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",tc++, s+1, d[ans], ans+1);
    }
}

