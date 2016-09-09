#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;
ll x[N], y[N];
int n;

ll cross (int i, int j, int k) {
    return (x[j]-x[i])*(y[k]-y[i]) - (x[k]-x[i])*(y[j]-y[i]);
}

int sgn (ll x) {
    return (x > 0) - (x < 0);
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%lld %lld",x+i,y+i);
    ll area = 0;
    for(int i = 1; i < n-1; i++) area += cross(0, i, i+1);

    int ans = 0;
    for(int j = 0; j < n; j++) {
        int i = (j-1+n)%n, k = (j+1)%n;
        ans += (sgn(cross(j,i,k)) == 1);
    }
    if(area < 0) ans = n-ans;
    printf("%d\n",ans);
}

