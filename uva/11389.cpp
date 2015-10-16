#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[150], e[150];
int n,d,r;

int main(){
    while(scanf("%d %d %d",&n,&d,&r) && n != 0) {
        for(int i = 0; i < n; i++)
            scanf("%d",&m[i]);
        for(int i = 0; i < n; i++)
            scanf("%d",&e[i]);
        sort(m,m+n);
        sort(e,e+n);
        ll ans = 0;
        for(int i = 0; i < n; i++)
            ans += max(0,r*(m[i] + e[n-i-1]-d));
        printf("%lld\n",ans);
    }
}
