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
const int N = 10004;
const int modn = 1000000007;

int t, n, v[15];

int solve (int x) {
    vector<int> c;
    for(int i = 0; i < n; i++) {
        if (x&1) {
            c.pb(i);
        }
        x >>= 1;
    }
    sort (c.begin(), c.end());
    bool f;
    int k = c.size();
    do {
        f = true;
        for(int i = 1; i < k-1; i++)
            if (v[c[i]] != c[i-1] && v[c[i]] != c[i+1]) f = false;
        if (k > 1) {
            if(v[c[0]] != c[1] && v[c[0]] != c[k-1]) f = false;
            if(v[c[k-1]] != c[k-2] && v[c[k-1]] != c[0]) f = false;
        }
        if(f) return 1;
    } while (next_permutation(c.begin(), c.end()));
    return 0;
}

int main() {
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++) {
        scanf("%d",&n);
        for(int i = 0; i < n; i++) scanf("%d",v+i), v[i]--;
        int ans = 0;
        for (int i = 1; i < (1 << n); i++)
            if(solve(i)) ans = max (ans, __builtin_popcount(i));
        printf("Case #%d: %d\n", tc, ans);
    }
}

