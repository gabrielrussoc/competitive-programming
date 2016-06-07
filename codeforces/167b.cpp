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
const int N = 202;
const int modn = 1000000007;

int n, l, k;
double p[N];
double memo[N][N][N+200];
int vis[N][N][N+200];
int a[N];

double dp (int i,  int w, int s) {
    if (i == n) {
        if (w >= l && s >= 200) return 1.;
        else return 0.;
    }
    double &me = memo[i][w][s];
    if(vis[i][w][s]) return me;
    vis[i][w][s] = 1;
    return me = p[i]*dp(i+1,w+1,min(400,s+a[i])) + (1-p[i])*dp(i+1,w,s);
}

int main() {
    scanf("%d %d %d",&n,&l,&k);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d",&x);
        p[i] = x * .01;
    }
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    printf("%lf\n",dp(0,0,k+200));
}

