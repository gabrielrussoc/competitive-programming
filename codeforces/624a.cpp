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

int main() {
    int d, l, v1, v2;
    scanf("%d %d %d %d",&d,&l,&v1,&v2);
    double ans;
    ans = double(-(d-l))/double((v2+v1));
    printf("%lf\n",ans);
}

