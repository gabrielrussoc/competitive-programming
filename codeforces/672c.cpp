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
const double inf = 1./0.;
//////////////0123456789
const int N = 10004;
const int modn = 1000000007;

typedef complex<double> point;

point v[N];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    point a, b, t;
    ll x, y;
    cin >> x >> y;
    a = point(x,y);
    cin >> x >> y;
    b = point(x,y);
    cin >> x >> y;
    t = point(x,y);

    cin >> n;
    double biga[2], bigb[2];
    biga[0] = biga[1] = inf;
    bigb[0] = bigb[1] = inf;

    double a = 0.;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v[i] = point (x,y);
        a += abs(v[i]-t);
    }
    a *= 2.;

    int a1, a2, b1, b2;
    a1 = a2 = b1 = b2 = -1;
    for(int i = 0; i < n; i++) {
        double d = abs(v[i]-t) - 2.*abs(v[i]-t);
        if(biga[0] > d-eps){
            biga[1] = biga[0];
            a2 = a1;
            biga[0] = d, a1 = i;
        }
        
        d = abs(b-v[i]) + abs(v[i]-t) - 2.*abs(v[i]-t);
        if(bigb[0] > d-eps) {
            bigb[1] = bigb[0];
            b2 = b1;
            bigb[0] = d, b1 = i;
        }
    }
    double ret = 0;
    printf("%.20lf\n",ret);

}

