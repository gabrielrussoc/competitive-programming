#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

ll MOD = 1e9+7;

int main() {
    int n;
    scanf("%d", &n);
    ll s = 0;
    for(int i= 0; i < n; i++) {
        ll a;
        scanf("%lld", &a);
        s = (s + a) % MOD;
    }
    ll pot = 1ll;
    for(int i = 0; i < n-1; i++)
        pot = (pot * 2ll) % MOD;
    pot = (pot + MOD - 1ll) % MOD;
    cout << (pot * s) % MOD << endl;

}

