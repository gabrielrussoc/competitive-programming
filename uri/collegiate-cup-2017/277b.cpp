#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 300005;
int n, q, a[N], p, acc[N];
ll tree[4*N];

struct compress {
    int val, freq;
    compress () {}
    compress (int val, int freq) : val(val), freq(freq) {}
} c[N];

ll resp(ll v, ll q) {
    q = min(q, v+1);
    return v*q - q*(q-1ll)/2ll;
}

void build(int k = 1, int l = 0, int r = p-1) {
    if(l == r) {
        tree[k] = resp(c[l].val, c[l].freq);
        return;
    }
    int m = (l + r) / 2;
    build(2*k, l, m);
    build(2*k+1, m+1, r);
    tree[k] = max(tree[2*k], tree[2*k+1]);
}

int get(int x) {
    int l = 0, r = p-1;
    while(l < r) {
        int m = (l + r) / 2;
        if(acc[m+1] >= x) r = m;
        else l = m + 1;
    }
    return l;
}

ll query(int fl, int fr, int k = 1, int l = 0, int r = p-1) {
    if(fl > fr || l > fr || r < fl) return 0; 
    if(l >= fl && r <= fr) return tree[k];
    int m = (l + r) / 2;
    return max(query(fl, fr, 2*k, l, m), query(fl, fr, 2*k+1, m+1, r));
}

ll calc(int ql, int l, int qr, int r) {
    ll v = c[ql].val;
    ll q = min(r-l+1, acc[ql+1]-l);
    ll ans = resp(v, q);
    
    v = c[qr].val;
    q = min(r-l+1, r + 1 - acc[qr]);
    ans = max(ans, resp(v,q));
    return ans;
}

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    int i, j;
    i = j = 0;
    while(j < n) {
        j = i;
        while(j < n && a[i] == a[j]) j++;
        c[p++] = compress(a[i], j-i);
        i = j;
    }
    for(int i = 0; i < p; i++) acc[i+1] = acc[i] + c[i].freq; 
    build();
    for(int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r); l--; r--;
        int ql = get(l+1);
        int qr = get(r+1);
        ll ans = query(ql+1, qr-1);
        ans = max(ans, calc(ql, l, qr, r));
        printf("%lld\n", ans);
    }
}

