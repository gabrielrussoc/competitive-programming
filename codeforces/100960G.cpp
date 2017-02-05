#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 212345;

int n, m, g;
ll f[N], c[N], q[N][2];

multiset<ll> ff;
ll bit[N];

void add(int idx, ll val) {
    for(int i = idx + 2; i < N; i += i&-i)
        bit[i] += val;
}

ll query(int idx){
    ll ret = 0;
    for(int i = idx + 2; i > 0; i -= i&-i)
        ret += bit[i];
    return ret;
}

int win(){
    if(n <= 2) return n;
    int ans = 2;
    ll s = *(ff.begin());
    s += *(++ff.begin());
    multiset<ll>::iterator it;
    while((it = ff.lower_bound(s)) != ff.end()) {
        int j = lower_bound(c, c+g, *it) - c; 
        if(query(j-1) <= *it) ans++; 
        s += *it;
    }
    return ans;
}


int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", f+i);
        c[i] = f[i];
        ff.insert(f[i]);
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i++) {
        scanf("%lld %lld", &q[i][0], &q[i][1]);
        q[i][0]--;
        c[n+i] = q[i][1];
    }

    sort(c, c+n+m);
    g = unique(c, c+n+m) - c;

    for(int i = 0; i < n; i++) add(lower_bound(c, c+g, f[i]) - c, f[i]);

    printf("%d\n", win());
    multiset<ll>::iterator it;
    for(int i = 0; i < m; i++) {
        int k = q[i][0];
        ll old = f[k];
        ff.erase(ff.lower_bound(old));
        f[k] = q[i][1];
        ff.insert(f[k]);
        int j = lower_bound(c, c+g, old) - c; 
        add(j, -old);
        j = lower_bound(c, c+g, f[k]) - c;
        add(j, f[k]);
        printf("%d\n", win());
    }
}

