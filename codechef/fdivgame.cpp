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

int t, n;
ll a;

int grundy(ll x) {
    int ret = 1;
    ll at = 1;
    int last = 1;
    while(at <= x) {
        last = ret;
        ret++;
        if(ret == 4) {
            at /= 2ll;
            at *= 3ll;
            ret = 0;
        }
        else at *= 2;
    }
    return last;
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            scanf("%lld",&a);
            ans ^= grundy(a);
        }
        if(ans) puts("Henry");
        else puts("Derek");
    }
}

