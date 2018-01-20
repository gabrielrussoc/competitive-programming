#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

ll p, k;
ll t[12];

int main() {
    scanf("%lld %lld", &k, &p);
    ll ans = 0;
    t[0] = 1;
    for(int i = 1; i < 8; i++) 
        t[i] = (t[i-1] * 10ll) % p;
    for(ll i = 1; i <= k; i++) {
        string s = to_string(i);
        int len = s.length();
        ans = (ans + (t[len] * i) % p) % p;
        reverse(s.begin(), s.end());
        ll r = stoll(s);
        ans = (ans + r) % p;
    }
    printf("%lld\n", ans);
}

