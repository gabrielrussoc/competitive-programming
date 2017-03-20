#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 51;
const int inf = 1234567;
int t, n, turn;
int memo[N][N*N][N];
int visi[N][N*N][N];
int a[N];

int f(int i) {
    i++;
    return i * (i-1) / 2;   
}

int dp(int i, int s, int l) {
    if(i == n) return s == f(n-1) ? 0 : inf;
    int &me = memo[i][s][l];
    if(visi[i][s][l] == turn) return me;
    visi[i][s][l] = turn;
    me = inf;
    for(int j = l; j <= n-1; j++) {
        if(j + s < f(i)) continue;
        me = min(me, abs(a[i] - j) + dp(i+1, s+j, j));
    }
    return me;
}

int main() {
    scanf("%d",&t);
    while(t--) {
        turn++;
        scanf("%d",&n);
        for(int i = 0; i < n; i++) scanf("%d",a+i);
        sort(a, a+n);
        printf("%d\n", dp(0,0,0));
    }
}

