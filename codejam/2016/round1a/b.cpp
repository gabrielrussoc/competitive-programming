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
const int N = 10004;
const int modn = 1000000007;

int t, x, f[2504], n;

int main() {
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        memset(f,0,sizeof f);
        scanf("%d",&n);
        for(int i = 0; i < 2*n-1; i++)
            for(int j = 0;j < n; j++) {
                scanf("%d",&x);
                f[x]++;
            }
        printf("Case #%d:",tc);
        for (int i = 0; i < 2501; i++)
            if(f[i]&1) printf(" %d",i);
        putchar('\n');
    }
}

