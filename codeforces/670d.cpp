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

ll a[N], b[N], r[N];
int n;
ll k;

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    ll lo = 0, hi = inf;
    while(lo < hi) {
        ll mid = (lo+hi+1)/2;
        ll dk = k;
        bool can = true;
        for(int i = 0; i < n; i++) {
            ll r = b[i]/a[i];
            if(r < mid) {
                ll inc = a[i]*mid - b[i];
                dk -= inc;
                if(dk < 0) {
                    can = false;
                    break;
                }
            }
        }
        if(can) lo = mid;
        else hi = mid-1;
    }
    cout << lo << endl;
        
}

