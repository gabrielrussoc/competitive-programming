#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1000006;
const ll MOD = 1e9+7;
int n, k;

ll fexp(ll b, ll e) {
    b = b % MOD;
    if(e == 0) return 1ll;
    if(e == 1) return b;
    if(e&1) return (b * fexp((b*b)%MOD, e/2)) % MOD;
    return fexp((b*b)%MOD, e/2) % MOD;
}

ll inv(ll x) {
    return fexp(x, MOD-2);
}

struct mod {
    ll x;
    mod() : x(0) {}
    mod(ll x) : x(x) {}
    mod operator+(const mod &o) const {
        return mod((x + o.x) % MOD);
    }
    mod operator-(const mod &o) const {
        return mod((x - o.x + MOD) % MOD);
    }
    mod operator*(const mod &o) const {
        return mod((x * o.x) % MOD);
    }
    mod operator/(const mod &o) const {
        return mod(x) * mod(inv(o.x));
    }
};

mod fac[N], acc[N], dp[N];

int main() {
    scanf("%d %d", &n, &k);
    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = mod(i) * fac[i-1];

    for(int i = k+2; i <= n; i++) {
        dp[i] = mod(i-k-1) * fac[i-2] + fac[i-2] * (acc[i-1] - acc[i-k-1]);
        acc[i] = acc[i-1] + dp[i] / fac[i-1];
    }

    mod ans = fac[n-1] * acc[n] - acc[k+1];
    printf("%lld\n", ans.x);
}

