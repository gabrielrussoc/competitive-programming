#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
int t, n, q, k;
int l[N];
ll acc[N];

bool can(int qt, int m) {
    ll have = acc[m] - acc[m-qt];
    ll total = ll(qt) * ll(k); 
    return total - have <= m - qt;
}

int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n, &q);
        for(int i = 0; i < n; i++) scanf("%d", l+i);
        sort(l, l+n);
        acc[0] = 0;
        for(int i = 0; i < n; i++) acc[i+1] = acc[i] + ll(l[i]);
        while(q--) {
            scanf("%d", &k);
            int g = lower_bound(l, l+n, k) - l;
            int ans = n - g;
            int lo = 0, hi = g;
            while(lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if(can(mid, g)) lo = mid;
                else hi = mid - 1;
            }
            ans += lo;
            printf("%d\n", ans);
        }
    }
}

