#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1003;
const ll inf = INT_MAX;

int n, m, opt[N][N];
ll dp[N][N], v[N];

int main() {
    while(scanf("%d %d",&n,&m) != EOF) {
        for(int i = 1; i <= m; i++) scanf("%lld",v+i);
        v[++m] = n; m++;
        v[0] = 0;
        for(int i = 0; i < m; i++) dp[i][i+1] = 0, opt[i][i+1] = i+1;

        for(int t = 2; t < m; t++) {
            for(int i = 0; i+t < m; i++) {
                ll best = inf;
                int bestj;
                for(int j = opt[i][i+t-1]; j <= opt[i+1][i+t]; j++) {
                    ll tmp = dp[i][j] + dp[j][i+t] + v[i+t] - v[i];
                    if(tmp < best) {
                        best = tmp;
                        bestj = j;
                    }
                }
                dp[i][i+t] = best;
                opt[i][i+t] = bestj;
            }
        }
        printf("%lld\n",dp[0][m-1]);
    }
}

