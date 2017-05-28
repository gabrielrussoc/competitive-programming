// adaptado de github.com/nathanpro
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
 
const int N = 2e5;
 
int T;
ll ans;
ll n, a, b, l, s[N];
 
ll f(ll x){
    ll loc = 0;
    for(ll i=0;i<n;i++)
        loc += abs(s[i] - (x + i*l));
    ans = min(ans, loc);
    return loc;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> n >> l >> a >> b;
        for(int i=0;i<n;i++) cin >> s[i];
        sort(s,s+n);

        ans = LLONG_MAX;
        ll lo = a,
           hi = b - n * l;
        while(256 < hi-lo){
            ll ds = (hi-lo)/3ll;
            ll t1 = lo + ds;
            ll t2 = lo + 2ll * ds;
            if(f(t1) <= f(t2)) hi = t2;
            else lo = t1;
        }
        for(ll i=lo;i<hi+1;i++) f(i);
        cout << ans << endl;
    }
}

