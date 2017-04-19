#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 212345;
ll a[N];

int main() {
    int n;
    ll p, q;
    scanf("%d %lld %lld", &n, &p, &q);
    ll maxi = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", a+i);
        maxi = max(maxi, a[i]);
    }
    ll lo = 1, hi = maxi;
    if(p == q) {
        printf("%lld\n", (maxi + p - 1) / p);
        return 0;
    }
    p -= q;
    while(lo < hi) {
        ll mid = (lo + hi) / 2;       
        ll s = 0;
        for(int i = 0; i < n; i++)
            s += (max(0ll, a[i] - mid * q) + p - 1) / p;
        if(s <= mid) hi = mid;
        else lo = mid+1;
    }
    printf("%lld\n", lo);
}