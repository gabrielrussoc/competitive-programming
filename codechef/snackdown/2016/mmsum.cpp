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

int t, n;
ll a[N], pre[N], suf[N];

int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i = 0; i < n; i++) scanf("%lld",a+i);
        pre[n-1] = 0;
        for(int i = n-2; i >= 0; i--) pre[i] = max(a[i+1], a[i+1] + pre[i+1]);
        suf[0] = 0;
        for(int i = 1; i < n; i++) suf[i] = max(a[i-1],a[i-1] + suf[i-1]);

        ll ans = -inf;
        for(int i = 0; i < n; i++) ans = max(ans, pre[i] + suf[i]);
        
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            ans = max(ans,sum);
            if(sum < 0) sum = 0;
        }
        printf("%lld\n",ans);
    }
}

