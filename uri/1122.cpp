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
const int inf = INT_MAX;
//////////////0123456789
const int N = 41;
const int F = 100005;
const int modn = 1000000007;

int v[N], ans[N];
int memo[N][F];
int n, f;

int dp(int i, int w) {
    if (i == n) return w == 56000;
    int &me = memo[i][w];
    if(me != -1) return me;
    me = 0;
    if(dp(i+1,w-v[i])) me |= 1;
    if(dp(i+1,w+v[i])) me |= 2;
    ans[i] |= me;
    return me;
}

int main() {
    while(scanf("%d %d",&n,&f) && n) {
        memset(memo,-1,sizeof memo);
        f += 56000;
        for(int i = 0; i < n; i++) scanf("%d",v+i), ans[i] = 0;
        if(!dp(0,f)) puts("*");
        else {
            for(int i = 0; i < n; i++) {
                if(ans[i] == 3) putchar('?');
                else if(ans[i] == 2) putchar('-');
                else putchar('+'); 
            }
            putchar('\n');
        }
    }
}

