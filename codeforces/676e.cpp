#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 100004;
const ll mod1 = 1000000007;
const ll mod2 = 217645177;
const ll mod3 = inf;

ll x1[N], x2[N], x3[N], k;
int n;

int main() {
    cin >> n >> k;
    x1[0] = x2[0] = x3[0] = 1;
    for(int i = 1; i <= n; i++) {
        x1[i] = (x1[i-1]*k)%mod1;
        x2[i] = (x2[i-1]*k)%mod2;
        x3[i] = (x3[i-1]*k)%mod3;
    }

    char buf[17];
    bool full = true;
    bool a0 = false;
    int jog = 0;
    ll ans1 = 0, ans2 = 0, ans3 = 0;
    ll val;
    for(int i = 0; i < n+1; i++) {
        scanf(" %s",buf);
        if(buf[0] == '?'){
            full = false;
            if(!i) a0 = true;
        } else {
            jog++;
            ll tmp = atoll(buf);
            if(!i) val = tmp;
            ans1 = (ans1 + tmp*x1[i])%mod1;
            ans2 = (ans2 + tmp*x2[i])%mod2;
            ans3 = (ans3 + tmp*x3[i])%mod3;
        }
    }

    if(!k) {
        if(a0) {
            if(jog&1) puts("Yes");
            else puts("No");
        } else {
            if(!val) puts("Yes");
            else puts("No");
        }
    } else {
        if(full) {
            if(ans2 == 0) puts("Yes");
            else puts("No");
        } else {
            if(n&1) puts("Yes");
            else puts("No");
        }
    }
}

