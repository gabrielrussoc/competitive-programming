#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 112345;

int n;
ll s, a[N], p[N];
ll k;

bool comp(ll i, ll j) {
    return a[i-1] + i * k < a[j-1] + j * k;
}

int main() {
    scanf("%d %lld",&n, &s);
    for(int i = 0; i < n; i++) scanf("%lld", a+i);
    for(int i = 0; i < n; i++) p[i] = i + 1;
    sort(p, p+n, comp);
    ll cost = 0;
    int lo = 0, hi = n;
    while(lo < hi) {
        k = (lo + hi + 1) / 2ll;
        sort(p, p+n, comp);
        cost = 0;
        ll ns = s;
        bool xab = false;
        for(int i = 0; i < k; i++) {
            ll at = k * p[i] + a[p[i]-1];
            if(at > ns) {
                xab = true;
                break;
            }
            cost += at;
            ns -= at;
        }
        if(!xab) lo = k;
        else hi = k - 1;
    }
    cost = 0;
    for(int i = 0; i < lo; i++) {
        cost += ll(lo) * p[i] + a[p[i]-1];
    }
    printf("%d %lld\n", lo, cost);
    
}

