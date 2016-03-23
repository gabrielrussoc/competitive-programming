#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 100004;
const int modn = 1000000007;

struct triple {
    int l, r;
    ll c;
    triple() {}
    triple (int a, int b, ll k) : l(a), r(b), c(k) {}
    bool operator < (const triple& o) const {
        return l < o.l;
    }
};

ll tree[4*N], lazy[4*N], x;
int n, m, l, r, t;
set<triple> s;

void unlazy(int k, ll q) {
    tree[k] += q*lazy[k];
    if(q > 1ll) {
        lazy[2*k] += lazy[k];
        lazy[2*k+1] += lazy[k];
    }
    lazy[k] = 0ll;
}

ll query(int k, int l, int r, int fl, int fr) {
    unlazy(k,(ll) r-l+1);
    if(l > fr || r < fl) return 0ll;
    if(l >= fl && r <= fr) return tree[k];
    int m = (l+r)/2;
    return query(2*k,l,m,fl,fr) + query(2*k+1,m+1,r,fl,fr);
}


void update(int k, int l, int r, int fl, int fr, ll v) {
    unlazy(k,(ll) r-l+1);
    if(l > fr || r < fl) return;
    if(l >= fl && r <= fr) {
        lazy[k] += v;
        unlazy(k, (ll) r-l+1);
        return;
    }
    int m = (l+r)/2;
    update(2*k,l,m,fl,fr,v);
    update(2*k+1,m+1,r,fl,fr,v);
    tree[k] = tree[2*k] + tree[2*k+1];
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++) s.insert(triple(i,i,ll(i))); 
    while (m--) {
        scanf("%d",&t);
        if(t == 1) {
            scanf("%d %d %I64d",&l,&r,&x);
            auto it = s.upper_bound(triple(l,r,x));
            if(it != s.begin()) it--;
            vector<triple> aux;
            while(it != s.end()) {
                triple a = *it;
                if(a.l > r) break;
                int esq = max(a.l,l);
                int dir = min(a.r,r);
                ll v = abs(a.c-x);
                if(dir >= esq) update(1,1,n,esq,dir,v);
                if(esq != a.l) aux.pb(triple(a.l,l-1,a.c));
                if(dir != a.r) aux.pb(triple(r+1,a.r,a.c));
                s.erase(it++);
            }
            for (triple a : aux) s.insert(a);
            s.insert(triple(l,r,x));
        } else {
            scanf("%d %d",&l,&r);
            printf("%I64d\n",query(1,1,n,l,r));
        }
    }
}

