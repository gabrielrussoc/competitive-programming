#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

map<ll, ll> f;

int main() {
    int n;
    ll s;
    scanf("%d %lld", &n, &s);
    ll pre = 0;
    f[pre] = 1;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll a;
        scanf("%lld", &a);
        pre += a;
        ans += f[pre-s];
        f[pre]++;
    }
    printf("%lld\n", ans);

}