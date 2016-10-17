#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1024;
const int MOD = 100000007;
int n, m, t, turn, a[N], b[N], memo[N][N], visi[N][N];

int dp(int i, int ac) {
    if(i == n) return b[ac] != turn;
    int &me = memo[i][ac];
    if(visi[i][ac] == turn) return me;
    visi[i][ac] = turn;
    return me = (dp(i+1,ac) + dp(i+1,ac^a[i]))%MOD;
}

int main() {
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        turn++;
        scanf("%d %d",&n,&m);
        for(int i = 0; i < n; i++) scanf("%d",a+i);
        for(int i = 0; i < m; i++) {
            int x;
            scanf("%d",&x);
            b[x] = turn;
        }
        printf("Case %d: %d\n",tc,dp(0,0));
    }
}

