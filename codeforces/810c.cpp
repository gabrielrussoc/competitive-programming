#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 300005;
ll MOD = 1e9+7;
ll d[N], dx[N], ad[N], adx[N];
int n;
ll x[N];

ll fexp (ll a, ll e) {
    ll t = 1;
    for(;e; e >>= 1, a = (a*a)%MOD)
        if(e&1) t = (a*t)%MOD;
    return t % MOD;
}

ll dumb() {
    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            ll pot = d[j-i-1];
            ll dif = (x[j] - x[i] + MOD) % MOD; 
            ll term = (pot * dif) % MOD;
            ans = (ans + term) % MOD;
        }
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%lld", x+i);
    sort(x, x+n);
    
    d[0] = 1ll;
    dx[0] = x[0];
    for(int i = 1; i <= n; i++) {
        d[i] = (d[i-1] * 2ll) % MOD; 
        dx[i] = (d[i] * x[i]) % MOD;
    }
    ad[0] = d[0];
    adx[0] = dx[0];
    for(int i = 1; i < n; i++) {
        ad[i] = (ad[i-1] + d[i]) % MOD;
        adx[i] = (adx[i-1] + dx[i]) % MOD;
    }

    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ll den = d[i+1];
        ll f = (adx[n-1] - adx[i] + MOD) % MOD;
        ll s = (ad[n-1] - ad[i] + MOD) % MOD;
        s = (x[i] * s) % MOD;
        ll num = (f - s + MOD) % MOD;
        ans = (ans + ((num * (fexp(den, MOD - 2) % MOD)) % MOD) % MOD);
    }
    printf("%lld\n", ans % MOD);
}

