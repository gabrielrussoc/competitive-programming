#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
const int T = 55;
const int N = 100005;

int t, m, n;
ll memo[T][N];
bool vis[T][N];

ll dp(int i, int q) {
    if(q < m || q > n) return 0;
    if(i == t-1) return 1;
    ll &me = memo[i][q];
    if(vis[i][q]) return me;
    vis[i][q] = 1;
    return me = (me + dp(i+1, q-1) + dp(i+1, q+1)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t >> m >> n;
    ll ans = 0;
    for(int i = m; i <= n; i++) ans = (ans + dp(0, i)) % MOD;
    cout << ans << endl;
}

