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
    int d, h, v, e;
    double PI = acos(-1);
    scanf("%d %d %d %d",&d,&h,&v,&e);
    double r = double(d) / 2.;
    double vol = PI * double(r * r) * double(h);
    double inc = double(e) * PI * double(r*r);
    double dec = v;
    if(inc-dec > eps) 
        puts("NO");
    else {
        puts("YES");
        printf("%lf\n",vol/(dec-inc));
    }

}

