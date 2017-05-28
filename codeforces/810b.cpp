#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
int n, f;
int k[N], l[N], p[N];

bool cmp(int i, int j) {
    int di = min(l[i], 2*k[i]) - min(l[i], k[i]);
    int dj = min(l[j], 2*k[j]) - min(l[j], k[j]);
    return di > dj;
}

int main() {
    scanf("%d %d",&n, &f);
    for(int i = 0; i < n; i++) scanf("%d %d", k+i, l+i);
    for(int i = 0; i < n; i++) p[i] = i;
    sort(p, p+n, cmp);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int qt = k[p[i]];
        int cl = l[p[i]];
        if(i < f) qt *= 2;
        ans += ll(min(qt, cl));
    }
    printf("%lld\n", ans);

}

