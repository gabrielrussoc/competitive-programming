#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

ll n, m;

ll f(ll i) {
    ll g = 2000000000000000000ll;
    if(i > g/i) return g;
    return i*(i+1ll)/2ll;
}

bool zero(ll i) {
    if(i <= m) return false;      
    i -= m;
    return n-m-f(i) <= 0ll;
}

int main() {
    scanf("%lld %lld", &n, &m);
    if(n <= m) printf("%lld\n", n);
    else {
        ll l = 1ll, r = n;
        while(l < r) {
            ll mid = (l+r)/2ll;
            if(zero(mid)) r = mid;
            else l = mid+1;
        } 
        printf("%lld\n", l);
    }
}

