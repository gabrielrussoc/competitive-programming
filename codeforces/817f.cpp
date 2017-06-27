#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

enum _ {NONE, ZERO, ONE, XOR};

const int N = 300005;
int tree[4*N], sz[4*N], lazy[4*N], p;
ll f[2*N];

struct _query {
    int t;
    ll l, r;
    _query() {}
    _query(int t, ll l, ll r) : t(t), l(l), r(r) {}
} query[N];

void uplazy(int k, int ty) {
    if(ty != XOR) lazy[k] = ty;
    else {
        if(lazy[k] == XOR) lazy[k] = NONE;
        else if(lazy[k] == NONE) lazy[k] = XOR;
        else if(lazy[k] == ONE) lazy[k] = ZERO;
        else lazy[k] = ONE;
    }
}

void unlazy(int k, bool leaf) {
    if(lazy[k] == NONE) return;

    if(lazy[k] == XOR) tree[k] = sz[k] - tree[k];
    else if(lazy[k] == ONE) tree[k] = sz[k]; 
    else tree[k] = 0;

    if(!leaf) {
        uplazy(2*k, lazy[k]);
        uplazy(2*k+1, lazy[k]);
    }

    lazy[k] = NONE;
}

void update(int fl, int fr, int ty, int k = 1, int l = 1, int r = p+1) {
    unlazy(k, l == r);
    if(l >= fl && r <= fr) {
        uplazy(k, ty);
        unlazy(k, l == r);
        return;
    }
    if(l > fr || r < fl) return;
    int m = (l + r) / 2;
    update(fl, fr, ty, 2*k, l, m);
    update(fl, fr, ty, 2*k+1, m+1, r);
    tree[k] = tree[2*k] + tree[2*k+1];
}

int mex(int k = 1, int l = 1, int r = p+1) {
    unlazy(k, l == r);
    if(tree[k] == 0) return l;
    int m = (l + r) / 2;
    unlazy(2*k, sz[2*k] == 1);
    if(tree[2*k] == sz[2*k]) {
        unlazy(2*k+1, sz[2*k+1] == 1);
        return mex(2*k+1, m+1, r);
    }
    return mex(2*k, l, m);
} 

void build(int k = 1, int l = 1, int r = p + 1) {
    sz[k] = r-l+1;
    if(l == r) return;
    int m = (l + r)/2;
    build(2*k, l, m);
    build(2*k+1, m+1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    int q = 0;
    for(int i = 0; i < n; i++) {
        int t;
        ll l, r;
        scanf("%d %lld %lld", &t, &l, &r);
        query[i] = _query(t, l, r);
        f[q++] = l;
        f[q++] = r;
        f[q++] = r+1ll;
    }
    f[q++] = 1;
    sort(f, f+q);
    p = unique(f, f+q) - f;
    build();
    for(int i = 0; i < n; i++) {
        int t = query[i].t;
        int l = lower_bound(f, f+p, query[i].l) - f + 1;
        int r = lower_bound(f, f+p, query[i].r) - f + 1;
        switch(t) {
            case 1:
                update(l, r, ONE);
                break;
            case 2:
                update(l, r, ZERO);
                break;
            case 3:
                update(l, r, XOR);
                break;
        }
        printf("%lld\n", f[mex()-1]);
    }
}

