#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 112345;
const int MAX = 2e6+7;
const int inf = 0x3f3f3f3f;

int n, x[N], y[N], tree[4*MAX][2], lazy[4*MAX];

struct event {
    int x, y, len;
    bool open;
    event() {}
    event(int x, int y, int len, bool open) : x(x), y(y), len(len), open(open) {}
    bool operator < (const event& o) const {
        if(x != o.x) return x < o.x;
        return y < o.y;
    }
} e[2*N];

void unlazy(int k, bool leaf) {
    tree[k][0] += lazy[k];
    if(!leaf) {
        lazy[2*k] += lazy[k];
        lazy[2*k+1] += lazy[k];
    }
    lazy[k] = 0;
}

pii query() {
    unlazy(1, 0);
    return pii(tree[1][0], tree[1][1]);
}

void update(int fl, int fr, int val, int k, int l, int r) {
    unlazy(k, l == r);
    if(r < fl || l > fr) return;
    if(l >= fl && r <= fr) {
        lazy[k] += val;
        unlazy(k, l == r);
        return;
    }
    int mid = l + (r-l) / 2;
    update(fl, fr, val, 2*k, l, mid);
    update(fl, fr, val, 2*k+1, mid+1, r); 
    int ml = tree[2*k][0], mr = tree[2*k+1][0];
    int fml = tree[2*k][1], fmr = tree[2*k+1][1];
    tree[k][0] = min(ml, mr);
    if(ml == mr) tree[k][1] = fml + fmr;
    else if(ml < mr) tree[k][1] = fml;
    else tree[k][1] = fmr;
}

void init(int k, int l, int r) {
    lazy[k] = 0;
    if(l == r) {
        tree[k][0] = 0;
        tree[k][1] = 1;
    } else {
        int mid = l + (r-l) / 2;
        init(2*k, l, mid);
        init(2*k+1, mid+1, r);
        tree[k][0] = 0;
        tree[k][1] = tree[2*k][1] + tree[2*k+1][1];
    }
}

bool can(int k) {
    for(int i = 0; i < n; i++) {
        e[2*i] = event(x[i] - k, y[i] + k, 2*k, true);
        e[2*i+1] = event(x[i] + k + 1, y[i] - k, 2*k, false); 
    }
    int p = 2*n;
    sort(e, e+p);
    init(1, -k, k);
    ll area = 0;
    int lx = -k;
    for(int i = 0; i < p; i++) {
        pii aux = query();
        int x = min(e[i].x, k + 1);
        if(x > lx) {
            ll dx = x - lx;
            ll dy = aux.first == 0 ? 2*k+1 - aux.second : 2*k+1;
            area += dy * dx;
        }
        if(e[i].open) update(e[i].y - e[i].len, e[i].y, 1, 1, -k, k);
        else update(e[i].y, e[i].y + e[i].len, -1, 1, -k, k);
        lx = max(lx, x);
    }
    ll me = ll(2*k+1) * ll(2*k+1);
    return area != me;
}

int main() {
    int tc = 1;
    while(scanf("%d",&n) && n != -1) {
        for(int i = 0; i < n; i++) scanf("%d %d", x+i, y+i);
        int lo = 0, hi = 1e6 + 1;
        while(lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if(can(mid)) lo = mid;
            else hi = mid - 1;
        }
        printf("Case %d: ", tc++); 
        if(lo == 1e6+1) puts("never");
        else printf("%d\n", lo + 1);
    }
}

