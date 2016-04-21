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
const int N = 100005;
const int modn = 1000000007;

int lc[N], rc[N], x[N], y[N], sz[N];
int ts, tam;
vector<int> in;
vector<int> tree[4*N];

struct triple {
    int f,s,t;
    triple () {}
    triple (int a, int b, int c) : f(a) , s(b) , t(c) {}
};

void build(int k = 1, int l = 0, int r = tam-1) {
    tree[k].clear();
    if(l == r) {
        tree[k].pb(in[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*k,l,mid);
    build(2*k+1,mid+1,r);
    merge(tree[2*k].begin(), tree[2*k].end(), tree[2*k+1].begin(), tree[2*k+1].end(), back_inserter(tree[k]));
}

int query(int fl, int fr, int num, int k=1, int l=0, int r=tam-1) {
    if(l > fr || r < fl) return 0;
    if(l >= fl && r <= fr)
        return lower_bound(tree[k].begin(), tree[k].end(), num) - tree[k].begin();
    int mid = (l+r)/2;
    return query(fl,fr,num,2*k,l,mid) + query(fl,fr,num,2*k+1,mid+1,r);
}

ll qry1(int s, int t, int k) {
    s--; t--;
    ll lo = 0, hi = inf;
    while(lo < hi) {
        ll mid = (lo+hi+1)/2;
        if(query(s,t,mid) < k) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

void upd(int t) {
    if(t == -1) return;
    sz[t] = 1;
    if(lc[t] != -1) sz[t] += sz[lc[t]];
    if(rc[t] != -1) sz[t] += sz[rc[t]];
}

void merge(int &t, int l, int r) {
    if(l == -1 || r == -1) t = l == -1 ? r : l;
    else if(y[l] < y[r]) merge(lc[r], l, lc[r]), t = r;
    else merge(rc[l], rc[l], r), t = l;
    upd(l), upd(r); 
}

void split (int k, int t, int &l, int &r) {
    if(t == -1) l = r = -1;
    else if(x[t] > k) split(k, lc[t], l ,lc[t]), r = t;
    else split(k, rc[t], rc[t], r), l = t; 
    upd(t);
}

void insert (int &t, int k) {
    int l, r;
    x[ts] = k;
    lc[ts] = rc[ts] = -1;
    split(k,t,l,r);
    merge(t,l,ts++);
    merge(t,t,r);
}

ll qry2 (int t, int k) {
    int l, r, ret;
    split(k, t, l, r);
    ret = sz[l];
    merge(t,l,r);
    return ret;
}

ll qry3 (int t, int k) {
    int qe = lc[t] != -1 ? sz[lc[t]] : 0;
    if(qe + 1 == k) return x[t];
    else if (qe+1 > k) return qry3(lc[t], k);
    else return qry3(rc[t], k-qe-1);
}


int main() {
    char buf[15];
    int x, s, t, k, treap, n;
    for(int i = 0; i < N; i++) y[i] = i;
    srand(time(NULL));
    random_shuffle(y,y+N);
    int tc = 1;
    while(scanf("%d",&n) != EOF) {
        in.clear();
        ts = 0;
        treap = -1;
        vector<triple> qq;
        ll q1,q2,q3;
        q1 = q2 = q3 = 0;
        for(int i = 0; i < n; i++) {
            scanf(" %s",buf);
            if(buf[0] == 'I') {
                scanf("%d",&x);
                insert(treap,x);
                in.pb(x);
            } else {
                int qr = buf[6]-'0';
                if(qr == 1) {
                    scanf("%d %d %d",&s,&t,&k);
                    qq.pb(triple(s,t,k));
                }
                else if(qr == 2) {
                    scanf("%d",&x);
                    q2 += qry2(treap, x);
                } else {
                    scanf("%d",&k);
                    q3 += qry3(treap, k);
                }
            }
        }
        tam = in.size();
        build();
        for(int i = 0; i < qq.size(); i++)
            q1 += qry1(qq[i].f, qq[i].s, qq[i].t);
        printf("Case %d:\n%lld\n%lld\n%lld\n",tc++,q1,q2,q3);
    }
}

