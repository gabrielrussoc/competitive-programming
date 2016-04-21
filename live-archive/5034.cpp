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

struct node {
    vector<int> v;
    node operator + (node a) const {
        node ret;
        int i, j, n, m;
        i = j = 0;
        n = v.size();
        m = a.v.size();
        while(i+j < n+m) {
            if(i == n) ret.v.pb(a.v[j++]);
            else if(j == m) ret.v.pb(v[i++]);
            else if (v[i] < a.v[j]) ret.v.pb(v[i++]);
            else ret.v.pb(a.v[j++]);
        }
        return ret;
    }
    node () {}
    node (int x) {
        v.pb(x);
    }
} tree[4*N];

void build(int k, int i, int j, int idx) {
    if(i == j) {
        tree[k] = node(in[idx]);
        return;
    }
    int mid = (i+j)/2;
    if(idx <= mid) build(2*k,i,mid,idx);
    else build(2*k+1,mid+1,j,idx);
    tree[k] = tree[2*k] + tree[2*k+1];
}

node query(int k, int l, int r, int fl, int fr) {
    if(l >= fl && r <= fr) return tree[k];
    if(l > fr || r < fl) return node();
    int mid = (l+r)/2;
    return query(2*k,l,mid,fl,fr) + query(2*k+1,mid+1,r,fl,fr);
}

int qry1(int s, int t, int k) {
    s--; t--;
    return query(1,0,tam-1,s,t).v[k-1];
}

void upd(int t) {
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

int qry2 (int t, int k) {
    int l, r, ret;
    split(k, t, l, r);
    ret = sz[l];
    merge(t,l,r);
    return ret;
}

int qry3 (int t, int k) {
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
        vector<tuple<int, int, int> > qq;
        int q1,q2,q3;
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
                    qq.pb(tie(s,t,k));
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
        for(int i = 0; i < tam; i++) build(1,0,tam-1,i);
        for(auto q : qq)
            q1 += qry1(get<0>(q), get<1>(q), get<2>(q));
        printf("Case %d:\n%d\n%d\n%d\n",tc++,q1,q2,q3);
    }
}

