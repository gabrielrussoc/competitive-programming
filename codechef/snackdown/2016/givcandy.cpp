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

ll mdc (ll a, ll b) {
    if(b == 0) return a;
    return mdc(b,a%b);
}

int main() {
    int t;
    ll a,b,c,d;
    scanf("%d",&t);
    while(t--) {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        ll x = mdc(c,d);
        ll ans = abs(a-b) % x;
        ans = min (ans, x-ans);
        printf("%lld\n",ans);
    }
}

