#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 53;
const int L = 1003;

int n, l;
int c[N];
int dp[N][N];
const int inf = 0x3f3f3f3f;

int main() {
    while(scanf("%d", &l) && l) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", c+i);
        c[n++] = 0; c[n++] = l;
        sort(c, c+n);
        
        for(int i = 0; i < n-1; i++) dp[i][i+1] = 0;
        for(int d = 3; d <= n; d++) {
            for(int i = 0; i <= n - d; i++) {
                int j = i + d - 1;
                dp[i][j] = inf;
                for(int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + c[j] - c[i]);
            }
        }
        printf("The minimum cutting is %d.\n", dp[0][n-1]);
    }
}

