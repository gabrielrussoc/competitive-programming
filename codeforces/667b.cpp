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
const int N = 100005;
const int modn = 1000000007;

ll v[N];

int main() {
    int n;
    scanf("%d",&n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(2*v[i] >= sum) {
            ans = max(ans, 2*v[i] - sum+1);
        }
    }
    cout << ans << endl;
}

