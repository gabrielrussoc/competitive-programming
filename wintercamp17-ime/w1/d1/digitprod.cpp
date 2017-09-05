#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100;
const ll MOD = 1e9+7;

struct state {
    int i;
    ll p;
    bool zero;

    state () {}
    state (int i, ll p, bool zero) : i(i), p(p), zero(zero) {}

    bool operator< (const state &o) const {
        if(i != o.i) return i < o.i;
        if(p != o.p) return p < o.p;
        return zero < o.zero;
    }
};

map<state, ll> memo;

ll dp(int i, ll p, bool zero) {
    if(i == N) return !zero && p == 1ll;
    state s = state(i, p, zero);
    if(memo.count(s)) return memo[s];
    ll ans = 0;
    if(zero) ans = dp(i+1, p, zero) % MOD;
    for(ll d = 1ll; d < 10ll; d++) {
        if(p % d == 0ll)
            ans = (ans + dp(i+1, p / d, false)) % MOD;
    } 
    memo[s] = ans % MOD;
    return ans % MOD;
}

ll me2[N][2];
int vis[N][2];

ll dp2(int i, bool zero) {
    if(i == N) return !zero;
    ll &me = me2[i][zero];
    if(vis[i][zero]) return me;
    vis[i][zero] = 1;
    ll ans = 0;
    if(zero) ans = dp2(i+1, zero);
    ans = (ans  + (9ll * dp2(i+1, false)) % MOD) % MOD;
    return me = ans;
}


int main() {
    ll p;
    int t;
    cin >> t;
    while(t--) {
        cin >> p;
        if(p) cout << dp(0, p, true) << endl;
        else {
            ll ten = 1ll;
            for(int i = 0; i < N; i++) ten = (ten * 10ll) % MOD;
            cout << (ten + MOD - dp2(0, true)) % MOD << endl;
        }
    }
}

