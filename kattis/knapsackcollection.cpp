#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 20004;
int n, s, t;
int k[N], first[N];
ll ans[N];

ll mdc(ll a, ll b) {
    if(!b) return a;
    return mdc(b, a % b);
}

int main() {
    scanf("%d %d %d",&n, &s, &t);
    for(int i = 0; i < n; i++) scanf("%d", k+i);
    for(int i = 0; i < n; i++) first[i] = k[i];
    sort(first, first+n);
    int g = unique(first, first+n) - first;

    ll at, tot = 0;
    ll mini = LLONG_MAX;
    ll maxi = -1;
    for(int i = 0; i < g; i++) {
        at = 0;
        multiset<int> ms;
        for(int j = 0; j < n; j++) ms.insert(k[j]);
        int slot = first[i]; 
        for(int j = 0; j < n; j++) {
            auto it = ms.find(slot);
            ms.erase(it);
            at += ll(t);
            if(ms.size() == 0) break;
            slot = (slot + t) % s;
            it = ms.lower_bound(slot);
            int nslot = *ms.begin();
            if(it != ms.end()) nslot = *it;
            at += ll((s + nslot - slot) % s);
            slot = nslot;
        }
        mini = min(at, mini);
        ans[i] = at;
    }
    for(int i = 0; i < s; i++) {
        int q = (lower_bound(first, first+g, i) - first) % g;
        ll loc = ll((s + first[q] - i) % s) + ans[q];
        tot += loc;
        maxi = max(maxi, loc);
    }
    printf("%lld\n", mini);
    printf("%lld\n", maxi);
    ll den = s;
    ll md = mdc(tot, den);
    printf("%lld/%lld\n", tot/md, den/md);
}
