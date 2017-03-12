#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;
int v[N], n;
const ll MOD = 1e9+7;

set<int> om, oM;

int nm(int i){
    set<int>::iterator it = om.lower_bound(i);
    if(it != om.end()) return *it;
    return n;
}

int nM(int i){
    set<int>::iterator it = oM.lower_bound(i);
    if(it != oM.end()) return *it;
    return n;
}

ll f(int e) {
    ll r = 1;
    while(e--) {
        r <<= 1;
        r %= MOD;
    }
    return (r + MOD - 1ll) % MOD;
}

ll g(int e) {
    return (f(e) + 1ll) % MOD;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i = 0; i < n; i++) scanf("%d",v+i);
        int mini = *min_element(v, v+n);
        int maxi = *max_element(v, v+n);
        int m, M;
        m = M = 0;
        om.clear(); oM.clear();
        for(int i = 0; i < n; i++) {
            if(v[i] == mini) {
                m++;
                om.insert(i);
            }
            if(v[i] == maxi){
                M++;
                oM.insert(i);
            }
        }
        ll seq;
        if(mini == maxi) seq = (f(m) * g(n-m)) % MOD;
        else seq = (((f(m) * f(M)) % MOD) * g(n-m-M)) % MOD;

        ll str = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] == mini) {
                int j = nM(i);
                str = (str + n-j) % MOD;
            } else if(v[i] == maxi) {
                int j = nm(i);
                str = (str + n-j) % MOD;
            } else {
                int j = max(nM(i), nm(i));
                str = (str + n-j) % MOD;
            }
        }
        printf("%lld %lld\n", str, seq);

    }
}

