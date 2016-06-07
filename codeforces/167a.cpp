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
const int N = 100004;
const int modn = 1000000007;

int n, a, d;
int v[N], t[N];

int main() {
    scanf("%d %d %d",&n,&a,&d);
    for (int i = 0; i < n; i++) scanf("%d %d",t+i, v+i);
    double last = -1;
    for(int i = 0; i < n; i++) {
        double tmax = double(v[i])/double(a);
        double cur = double(a) * tmax * tmax * .5;
        double need;
        if (cur >= d) need = sqrt (2.* d / double (a));
        else need = tmax + double(d-cur) / double(v[i]);
        double ans = need+t[i];
        if(ans <= last) ans = last;
        printf("%.20lf\n",ans);
        last = ans;
    }

}

