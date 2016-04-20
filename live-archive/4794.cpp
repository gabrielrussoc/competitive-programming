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
const int N = 104;
const int modn = 1000000007;

int n, memo[N][N][1<<15+2], v[17], sum[1<<15+2];

string bin(int x) {
    string ret;
    if(x == 0) return "";
    if(x&1) ret = "1";
    else ret = "0";
    return bin(x>>1) + ret;
}

void pre(){
    for(int i = 0; i < 1<<n; i++){
        int tot = 0;
        for(int j = 0; j < n; j++)
            if(i & (1<<j)) tot += v[j];
        sum[i] = tot;
    }
}

int dp (int x, int y, int mask) {
    if(__builtin_popcount(mask) == 1) return 1;
    int &me = memo[x][y][mask];
    if(me != -1) return me;
    me = 0;
    for(gerasubconjunto) {
       
    }
}

int main() {
    int x,y, tc = 1;
    while(scanf("%d",&n) && n) {
        int tot = 0;
        scanf("%d %d",&x, &y);  
        for(int i = 0; i < n; i++) scanf("%d",v+i), tot += v[i];
        if(tot != x*y) {
            printf("Case %d: No\n", tc++);
            continue;
        }
        pre();
        memset(memo,-1,sizeof memo);
        printf("Case %d: %s\n",tc++,dp(x,y,(1<<n) - 1) ? "Yes" : "No" );
    }
}

