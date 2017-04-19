#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define GNU __gnu_pbds
#define pb push_back
using namespace std;
typedef long long ll;

namespace GNU { typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; }
using GNU::ordered_set;

const int N = 212345;
ordered_set bit[N];
int n, p[N], a[N], b[N], c[N];

bool comp(int i, int j) {
    if(a[i] != a[j]) return a[i] < a[j];
    else if(b[i] != b[j]) return b[i] < b[j];
    return c[i] < c[j];
}

ll query(int x, int y) {
    ll ret = 0;
    for(int i = x + 2; i > 0; i -= i&-i) {
        ret += ll(bit[i].order_of_key(y));
    }
    return ret;
}

void update(int x, int y) {
    for(int i = x + 2; i < n + 7; i += i&-i) {
        bit[i].insert(y);
    }
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", a+i, b+i, c+i);
        p[i] = i;
    }
    sort(p, p+n, comp);
    ll ans = 0;
    for(int _i = 0; _i < n; _i++) {
        int i = p[_i];
        ans += _i - query(b[i], c[i]);
        update(b[i], c[i]);
    }
    printf("%lld\n", ans);
}