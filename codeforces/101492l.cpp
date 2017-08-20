#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int M = 102;
const int N = 1000006;

int m, n, k;
string p, t;
int dp[M][N];

int main() {
    cin >> m >> n >> k;
    cin >> p;
    cin >> t;

    for(int i = 0; i < m; i++) dp[i][n] = m-i;
    for(int j = 0; j < n; j++) dp[m][j] = 0;

    for(int i = m-1; i >= 0; i--)
        for(int j = n-1; j >= 0; j--) 
            if(p[i] == t[j]) dp[i][j] = dp[i+1][j+1];
            else dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));

    int ans = N;
    for(int i = 0; i < n; i++) ans = min(ans, dp[0][i]);
    puts(ans <= k ? "S" : "N");
}

