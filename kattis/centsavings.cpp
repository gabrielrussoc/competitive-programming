#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 2004;
const int D = 22;
const int inf = 0x3f3f3f3f;

int n, d;
int p[N], acc[N];
int memo[N][D], vis[N][D];

int cost(int i, int j) {
    int tot = acc[j+1] - acc[i];
    int last = tot % 10;
    if(last < 5) tot -= last;
    else tot += 10-last; 
    return tot;
}

int dp(int i, int d) {
    if(d == 0) return cost(i, n-1);
    if(i == n) return d ? inf : 0;
    int &me = memo[i][d];
    if(vis[i][d]) return me;
    vis[i][d] = true;
    me = inf;
    for(int j = i; j < n; j++) me = min(me, dp(j+1, d-1) + cost(i, j));
    return me;
}

int main() {
    scanf("%d %d",&n, &d);
    for(int i = 0; i < n; i++) scanf("%d", p+i);
    acc[0] = 0;
    for(int i = 0; i < n; i++) acc[i+1] = acc[i] + p[i];
    int ans = inf;
    for(int i = 1; i <= d; i++) ans = min(ans, dp(0, i));
    printf("%d\n", ans);
}

