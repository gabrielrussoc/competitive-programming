#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;

int n;
ll x[N], r[N];
int tree[4*N][2];
const int inf = 0x3f3f3f3f;

void build(int k = 1, int l = 0, int r = n-1) {
    tree[k][0] = -1;
    tree[k][1] = inf;
    if(l == r) return;
    int m = (l+r)/2;
    build(2*k, l, m);
    build(2*k+1, m+1, r);
}

void update(int fi, int val, int tr, int k = 1, int l = 0, int r = n-1) {
    if(l == r) {
        tree[k][tr] = val;
        return;
    }
    int m = (l+r)/2;
    if(fi <= m) update(fi, val, tr, 2*k, l, m);
    else update(fi, val, tr, 2*k+1, m+1, r);
    if(tr == 0) tree[k][tr] = max(tree[2*k][tr], tree[2*k+1][tr]);
    else tree[k][tr] = min(tree[2*k][tr], tree[2*k+1][tr]);
}

int query(int fl, int fr, int tr, int k = 1, int l = 0, int r = n-1) {
    if(l >= fl && r <= fr) return tree[k][tr];
    if(l > fr || r < fl) return tr ? inf : -1;
    int m = (l+r)/2;
    if(tr == 0) return max(query(fl, fr, tr, 2*k, l, m), query(fl, fr, tr, 2*k+1, m+1, r));
    return min(query(fl, fr, tr, 2*k, l, m), query(fl, fr, tr, 2*k+1, m+1, r));
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        build();
        for(int i = 0; i < n; i++) scanf("%lld %lld", x+i, r+i);
        update(n-1, n-1, 0);
        for(int i = n-2; i >= 0; i--) {
            int j = upper_bound(x, x+n, x[i]+r[i]) - x - 1;
            if(j == i) update(i, i, 0);
            else update(i, query(i+1, j, 0), 0);
        }
        update(0, 0, 1);
        for(int j = 1; j < n; j++) {
            int i = lower_bound(x, x+n, x[j]-r[j]) - x;
            if(i == j) update(j, j, 1);
            else update(j, query(i, j-1, 1), 1);
        }
        for(int i = 0; i < n; i++) {
            printf("%d%c", query(i, i, 0) - query(i, i, 1) + 1, " \n"[i==n-1]);
        }
    }
}

