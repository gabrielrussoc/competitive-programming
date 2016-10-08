#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 4003;
const int K = 807;
const int inf = 1e9+7;
int n, m;
int cost[N][N], dp[K][N], a[N][N], acc[N][N];
char s[2*N];

void calc(int a, int b, int l, int r, int k){
    if(a > b) return;
    int best = inf, besti;
    int m = (a+b)/2;
    for(int i = l; i <= min(r,m); i++) {
        int tmp = dp[k-1][i] + cost[i+1][m];
        if(tmp < best) {
            best = tmp;
            besti = i;
        }
    }
    dp[k][m] = best;
    calc(a,m-1,l,besti,k);
    calc(m+1,b,besti,r,k);
}

int main() {
    scanf("%d %d",&n,&m); m--;
    for(int i = 0; i < n; i++) {
        scanf (" %[^\n]", s);
        for(int j = 0; j < n; j++)
            a[i][j] = s[2*j]-'0';
    }
    acc[0][0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            acc[i+1][j+1] = a[i][j] + acc[i][j+1] + acc[i+1][j] - acc[i][j];

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            cost[i][j] = (acc[j+1][j+1] - acc[i][j+1] - acc[j+1][i] + acc[i][i])/2;

    for(int i = 0; i < n; i++) dp[0][i] = cost[0][i];
    for(int k = 1; k <= m; k++) calc(0,n-1,0,n-1,k);
    cout << dp[m][n-1] << '\n';
}

