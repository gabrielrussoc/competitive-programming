#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 500005;

int n, t, cs;
ll x, a[N], acc[N], all[3*N];
int tree[12*N];

void init(int k = 1, int l = 0, int r = 3*cs) {
    tree[k] = -1;
    if(l == r) return;
    int m = (l+r)/2;
    init(2*k, l, m);
    init(2*k+1, m+1, r);
}

int query(int fl, int k = 1, int l = 0, int r = 3*cs) {
    if(r <= fl) return tree[k];
    if(l > fl) return -1;
    int m = (l+r)/2;
    return max(query(fl, 2*k, l, m), query(fl, 2*k+1, m+1, r));
}

void update(int i, int v, int k = 1, int l = 0, int r = 3*cs) {
    if(l == r) {
        tree[k] = v;
        return;
    }
    int m = (l+r)/2;
    if(i <= m) update(i, v, 2*k, l, m);
    else update(i, v, 2*k+1, m+1, r);
    tree[k] = max(tree[2*k], tree[2*k+1]);
}

int neu(ll num) {
    return lower_bound(all, all+cs, num) - all;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> x;
        acc[0] = 0;
        cs = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            acc[i+1] = acc[i] + a[i];
            all[cs++] = a[i];
            all[cs++] = acc[i+1];
            all[cs++] = acc[i+1]-x;
        }
        sort(all, all+cs);
        cs = unique(all, all+cs) - all; 
        init();
        int ans = N;
        for(int i = 0; i < n; i++) {
            if(acc[i+1] >= x) ans = min(ans, i+1);
            int j = query(neu(acc[i+1]-x));
            if(j != -1) ans = min(ans, i-j);
            update(neu(acc[i+1]), i);
        }
        if(ans == N) ans = -1;
        cout << ans << endl;
    }
}

