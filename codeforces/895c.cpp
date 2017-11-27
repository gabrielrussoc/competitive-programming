#include <bits/stdc++.h>
#define div aushsaduihfa
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100005;
const int A = 71;
const ll MOD = 1e9+7;
int a[N], n;
int div[A], mask[A];
int ps, pos[A];
ll f[A], odd[A], even[A];
int memo[A][1<<19];
ll fat[N], ifat[N];

ll fexp(ll x, int e) {
    if(e == 0) return 1;
    if(e == 1) return x % MOD;
    if(e&1) return (x * fexp((x*x)%MOD, e/2)) % MOD; 
    return fexp((x*x)%MOD, e/2) % MOD;
}

ll dp(int i, int m) {
    if(i == 71) return m == 0;
    int &me = memo[i][m];
    if(me != -1) return me;
    return me = (dp(i+1, m) * even[i] + dp(i+1, m^mask[i]) * odd[i]) % MOD;
}

ll c(int n, int k) {
    if(k > n) return 0;
    return (((fat[n] * ifat[n-k]) % MOD) * ifat[k]) % MOD;
}

int main() {
    memset(memo, -1, sizeof memo);
    for(int i = 2; i < A; i++) {
        if(div[i]) continue;
        pos[i] = ps++;
        for(int j = i; j < A; j += i)
            div[j] = i;
    }

    fat[0] = 1;
    ifat[0] = 1;
    for(int i = 1; i < N; i++) {
        fat[i] = (fat[i-1] * ll(i)) % MOD;
        ifat[i] = fexp(fat[i], MOD-2);
    }
    for(int i = 1; i < A; i++) {
        int q = i;
        while(q > 1) {
            mask[i] ^= (1<<pos[div[q]]);
            q /= div[q];
        }
    }
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a+i);
        f[a[i]]++;
    }

    for(int i = 1; i <= 70; i++) {
        for(int k = 0; k <= f[i]; k += 2) even[i] = (even[i] + c(f[i], k)) % MOD;
        for(int k = 1; k <= f[i]; k += 2) odd[i]  = (odd[i] + c(f[i], k)) % MOD;
    }
    printf("%lld\n", (MOD + dp(1, 0) -1ll) % MOD);
}

