#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 212345;
multiset<ll> h;

int main() {
    int n;
    scanf("%d", &n);
    ll s = 0;
    ll lt = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ll t, d;
        scanf("%lld %lld", &t, &d);
        s += t - lt;
        h.insert(d);
        if(d > s) {
            ans++;
            ll q = *prev(h.end());
            h.erase(prev(h.end()));
            s += q;
        } 
        s -= d;
        lt = t;
    }
    printf("%d\n", ans);
}