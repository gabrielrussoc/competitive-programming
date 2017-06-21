#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

ll n, s;

bool big(ll x) {
    ll sum = 0;
    ll o = x;
    while(x) {
        sum += x%10ll;
        x /= 10;
    }
    return o - sum >= s;
}

int main() {
    cin >> n >> s;
    ll lo = 0, hi = n+1ll;
    while(lo < hi) {
        ll mid = (lo + hi)/2ll;
        if(big(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << n - lo + 1ll << endl;
}

