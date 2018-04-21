#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 105;
const int K = 15;
const int MOD = 1e8;
int n1, n2, k1, k2;
int dp[N][N][K][K];

int main() {
    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    for(int i = n1; i >= 0; i--)
        for(int j = n2; j >= 0; j--)
            for(int k = 0; k <= k1; k++)
                for(int l = 0; l <= k2; l++) {
                    if(i == n1 && j == n2) dp[i][j][k][l] = 1;
                    else dp[i][j][k][l] = (dp[i][j][k][l] + dp[i+1][j][k+1][0] + dp[i][j+1][0][l+1]) % MOD;
                }
    printf("%d\n", dp[0][0][0][0]);
}

