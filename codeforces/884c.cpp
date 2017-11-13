#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;

int n;
int p[N], r[N], c[N], vis[N];

int calc(int u, int r) {
    if(vis[u]) {
        c[r] = 1;
        return 0;
    }
    vis[u] = 1;
    if(p[u] != u) return 1 + calc(p[u], r);
    return 1;
}

ll eval(ll x, bool f) {
    if(f) return x*x;
    return x*(x+1ll)/2ll;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) r[i] = true;
    for(int i = 0; i < n; i++) { 
        scanf("%d", p+i); 
        p[i]--; 
        r[p[i]] = false;
    }

    vector<ll> cmp;
    for(int i = 0; i < n; i++) if(!r[i]) cmp.pb(calc(i, i)); 
    for(int i = 0; i < n; i++) if(!vis[i]) cmp.pb(calc(i,i));
    sort(cmp.begin(), cmp.end(), greater<ll>());
    ll ans = 0;
    if(cmp.size() == 1) ans = eval(cmp[0], c[0]);
    else {
        ans = eval(cmp[0]+cmp[1], 1);
        for(int i = 2; i < n; i++) ans += eval(cmp[i], c[i]);
    }
    printf("%lld\n", ans);
}

