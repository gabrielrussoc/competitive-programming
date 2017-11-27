#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
int n;
ll x, k;
ll a[N];

ll lt(ll x) {
    int i = lower_bound(a, a+n, x) - a;
    return i;
}

ll calc(ll v) {
    if(v % x == 0) return v / x;
    return (v - v%x + x) / x;
}

int main() {
    scanf("%d %lld %lld", &n, &x, &k);
    for(int i = 0; i < n; i++) scanf("%lld", a+i);
    sort(a, a+n);

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll q = calc(a[i]);
        ll b = lt(x*(q+k));
        ll aa = lt(x*(q+k-1ll));
        if(k == 0) {
            if(a[i] % x == 0) aa = b; 
            else aa = lt(a[i]);
        }
        ans += b - aa;
    }
    printf("%lld\n", ans);
}

