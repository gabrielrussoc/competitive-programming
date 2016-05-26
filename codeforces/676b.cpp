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
int n, t;
int ans = 0;
double qt[15][15];

int main() {
    scanf("%d %d",&n, &t);
    qt[0][0] = t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(qt[i][j] > 1-eps) {
                double l = qt[i][j]-1;
                l *= .5;
                ans++;
                qt[i+1][j] += l; qt[i+1][j+1] += l;
            }
        }
    }
    printf("%d\n",ans);
}

