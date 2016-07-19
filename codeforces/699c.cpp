#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 123456;
//////////////0123456789
const int N = 155;
const int modn = 1000000007;

int n;
int a[N];
int memo[N][9];

int dp(int i, int l) {
    if(i == n) return 0;
    int &me = memo[i][l];
    if(me != -1) return me;
    me = inf;
    if(a[i] == 0) { //nao contest e nao gym
        return me = 1 + dp(i+1,0);
    }
    if(a[i] == 1) { //sim contest e nao gym
        me = 1 + dp(i+1,0); 
        if(l != 2) me = min(me, dp(i+1,2));
        return me;
    }
    if(a[i] == 2) { //nao contest e sim gym
        me = 1 + dp(i+1,0);
        if(l != 1) me = min(me, dp(i+1,1));
        return me;
    }
    if(a[i] == 3) { //sim contest e sim gym
        me = 1 + dp(i+1,0);
        if(l != 1) me = min(me, dp(i+1,1));
        if(l != 2) me = min(me, dp(i+1,2));
        return me;
    }
    return me;
}

int main() {
    memset(memo,-1,sizeof memo);
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    printf("%d\n",dp(0,7));
}

