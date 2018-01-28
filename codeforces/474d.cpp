#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
const int MOD = 1e9+7;
ll dp[N], acc[N];

int main() {
    int t, k;
    scanf("%d %d", &t, &k);
    for(int i = 0; i < k; i++) dp[i] = 1;
    for(int i = k; i < N; i++) dp[i] = (dp[i-k] + dp[i-1]) % MOD;
    for(int i = 0; i < N; i++) acc[i+1] = (acc[i] + dp[i]) % MOD;
    while(t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", (acc[b+1] - acc[a] + MOD) % MOD);
    }
}



