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
const int N = 100019;
const int modn = 1000000007;

int bit[N], v[N], c[N], n;
int f[N], s[N];

int query (int idx) {
    int sum = 0;
    for(int i = idx+4; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

void update (int idx, int val) {
    for(int i = idx+4; i < N; i += i&-i)
        bit[i] += val;
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",v+i);
    for(int i = 0; i < n; i++) c[i] = v[i], f[i] = -1;
    sort(c,c+n);
    int g = unique(c,c+n) - c;
    for(int i = 0; i < n; i++) v[i] = lower_bound(c,c+g,v[i]) - c;
    for(int i = 0; i < n; i++) {
        if(f[v[i]] == -1) f[v[i]] = i; 
        else s[v[i]] = i;
        update(i,1);
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[v[i]] == i) continue; 
        update(s[v[i]],-1);
        update(i,-1);
        ans += ll(query(s[v[i]]) - query(i));
    }
    printf("%lld\n",ans);

}

