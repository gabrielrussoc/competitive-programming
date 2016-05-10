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
const int modn = 1000000007;

int t, n, q;
int tree[2*N];

void build() {
    for(int i = n-1; i > 0; i--) tree[i] = min(tree[i<<1],tree[i<<1|1]);
}

int query (int l, int r) {
    int ans = inf;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l&1) ans = min(ans, tree[l++]);
        if(r&1) ans = min(ans, tree[--r]);
    }
    return ans;
}

int main() {
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        printf("Scenario #%d:\n", tc);
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++) scanf("%d",tree+i+n);
        build();
        while(q--) {
            int a, b;
            scanf("%d %d",&a,&b); a--;
            printf("%d\n\n", query(a,b));
        }
    }
}

