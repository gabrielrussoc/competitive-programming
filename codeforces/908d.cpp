#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

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
    mod(ll _x) : x(_x) {}
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

const int N = 1003;

mod memo[N][N];
bool vis[N][N];
int k, pa, pb;
mod p;

mod dp(int a, int f) {
    if(f >= k) return 0;
    if(a+f >= k) return ((mod(1) - p) / p) + mod(a);
    if(vis[a][f]) return memo[a][f];
    vis[a][f] = 1;
    return memo[a][f] = ((mod(1) - p) * dp(a+1, f)) + (p * (dp(a, f+a) + a));
}

int main() {
    scanf("%d %d %d", &k, &pa, &pb);
    p = mod(pb) / mod(pa+pb);
    printf("%lld\n", (mod(1) / (mod(1) - p) * dp(0, 0)).x);
}

