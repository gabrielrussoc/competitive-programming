#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

bool good(ll a, ll b, ll c) {
    if(a < b) swap(a, b);
    if(c < a) return true;
    if(a*b - c < a) return true;

    for(ll d = 1ll; d*d <= c; d++) {
        if(c % d) continue;
        if(d <= b && c/d <= a) return true;
    }

    ll p = a*b - c;
    for(ll d = 1ll; d*d <= p; d++) {
        if(p % d) continue;
        if(d <= b && p/d <= a) return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a*b == c) puts("0");
        else if(c%a == 0ll || c%b == 0ll) puts("1");
        else if(good(a,b,c)) puts("2");
        else puts("3"); 
    }
}

