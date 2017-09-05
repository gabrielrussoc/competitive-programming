#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1003;
const ll MOD = 1e9+9;
ll memo[N][2*N];
bool vis[N][2*N];
int n, a[N], b[N];
char s[N];

ll dp(int i, int t) {
    if(i == N+1) return 0;
    ll &me = memo[i][t];
    if(vis[i][t]) return me;
    me = t == 1000;
    vis[i][t] = true;
    return me = (me + dp(a[i] + 1, t+1) + dp(b[i] + 1, t - 1)) % MOD;
}

int main() {
    scanf(" %s", s);
    n = strlen(s);
    a[n] = b[n] = N;
    for(int i = n-1; i >= 0; i--) {
        a[i] = s[i] == 'a' ? i : a[i+1];
        b[i] = s[i] == 'b' ? i : b[i+1];
    }
    printf("%lld\n", dp(0, 1000));
}

