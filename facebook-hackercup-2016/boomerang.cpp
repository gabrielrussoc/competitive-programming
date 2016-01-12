#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
    ll x, y;
} v[2005];

ll dq (point a, point b){
   return (a.x - b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

ll pick2 (ll x){
    if(x < 2) return 0;
    return (x*(x-1))/2;
}

int main(){
    int t, n;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%lld %lld",&v[i].x,&v[i].y);
        
        ll ans = 0;
        for(int i = 0; i < n; i++){
            map<ll,ll> m;
            for(int j = 0; j < n; j++){
                if(j != i){
                    m[dq(v[i],v[j])]++;
                }
            }
            for (map<ll,ll>::iterator it = m.begin(); it != m.end(); ++it){
                ans += pick2(it->second); 
            }
        }
        printf("Case #%d: %lld\n",tc,ans);
    }
}
