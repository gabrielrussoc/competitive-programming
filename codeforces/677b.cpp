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

ll n, h, k;
ll a[N];

int main() {
    cin >> n >> h >> k;
    ll tot = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(tot + a[i] <= h) { tot += a[i]; continue; }
        ll gap = h-tot;
        ll j = (a[i]-gap+k-1)/k;
        ans += j;
        tot = max(0ll, tot-j*k);
        i--;
    }
    if(tot) ans += (tot+k-1)/k;
    cout << ans << endl;

}

