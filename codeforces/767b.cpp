#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    ll ts, tf, t;
    int n;
    queue<ll> q;
    scanf("%lld %lld %lld",&ts, &tf, &t);
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        q.push(x);
    }
    map<ll, ll> m;
    ll at = ts;
    ll ans = -1;
    ll f = q.front();
    while(!q.empty()) {
        ll nx = q.front();
        if(nx > at && at + t <= tf) ans = at;
        ll nat = max(nx, at) + t;
        m[nx] = nat;
        at = nat;
        q.pop();
    }
    if(at + t <= tf) ans = at;
    ll lk = -1;
    if(ans == -1) {
        ll b = ts - f + 1;
        ans = f - 1;
        for(auto p : m){
            if(p.second - p.first < b && p.second + t <= tf) {
                b = p.second - p.first;
                ans = p.first;               
            }
            if(lk != -1 && !m.count(p.first - 1)) {
                if(m[lk] - p.first + 1 < b && m[lk] + t <= tf) {
                    b = m[lk] - p.first + 1;
                    ans = p.first - 1;
                }
            }
            lk = p.first;
        }
    }
    printf("%lld\n", ans);
}

