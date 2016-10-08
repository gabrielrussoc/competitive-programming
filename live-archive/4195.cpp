#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1024;
const int inf = 1e9+7;
int acc[N], v[N], cost[N][N], dp[N][N];
int n, m;

void calc(int a, int b, int l, int r, int k){
    if(a > b) return;
    int m = (a+b)/2;
    int best = inf,  besti;
    for(int i = l; i <= min(r,m); i++) {
        int tmp = dp[k-1][i] + cost[i+1][m];
        if (tmp < best) {
            best = tmp;
            besti = i;
        }
    }
    dp[k][m] = best;
    calc(a,m-1,0,besti,k);
    calc(m+1,b,besti,r,k);
}

int main() {
    while(scanf("%d %d",&n,&m) != EOF && n) {
        for(int i = 0; i < n; i++) scanf("%d",v+i);
        acc[0] = 0;
        for(int i = 0; i < n; i++) { 
            acc[i+1] = v[i] + acc[i]; 
            cost[i][i] = 0; 
        }
        for(int t = 1; t < n; t++)
            for(int i = 0; i+t < n; i++)
                cost[i][i+t] = cost[i][i+t-1] + v[i+t]*(acc[i+t]-acc[i]); 

        for(int i = 0; i < n; i++) dp[0][i] = cost[0][i];
        for(int k = 1; k <= m; k++) calc(0,n-1,0,n-1,k);
        printf("%d\n",dp[m][n-1]);
    }
}

