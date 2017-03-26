#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    vector<ll> div;
    ll i;
    for(i = 1; i*i < n; i++) {
        if(n % i == 0) {
            div.pb(i);
            div.pb(n/i);
        }
    }
    if(i*i == n) div.pb(i);
    sort(div.begin(), div.end());
    if(div.size() < k) puts("-1");
    else printf("%lld\n", div[k-1]);
}

