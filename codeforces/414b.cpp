#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 2003;
const int MOD = 1e9+7;
int n, k;
int dp[N][N];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i <= n; i++) dp[k][i] = 1;
    for(int i = k-1; i >= 0; i--)
        for(int j = 1; j <= n; j++)
            for(int m = j; m <= n; m += j)
                dp[i][j] = (dp[i][j] + dp[i+1][m]) % MOD;
    printf("%d\n", dp[0][1]);
}

