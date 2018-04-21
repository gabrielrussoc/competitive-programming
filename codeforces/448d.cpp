#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

ll n, m, k;

ll count(ll q) {
    ll ans = 0;
    for(ll i = 1; i <= n; i++)
        ans += min(q / i, m);
    return ans;
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    ll lo = 1, hi = n*m;
    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        if(count(mid) >= k) hi = mid;
        else lo = mid+1;
    }
    printf("%lld\n", lo);

}

