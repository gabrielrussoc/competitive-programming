#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    ll n, a, b, c;
    scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
    ll k = (4ll - n%4ll);
    if (k == 4ll) k = 0;
    ll ans = 0;
    if (k == 1ll) ans = min(a, min (b+c, c+c+c));
    else if (k == 2ll) ans = min(b, min(a+a, c+c));
    else if (k == 3ll) ans = min(c, min(a+a+a, a+b));
    printf("%lld\n",ans);
}

