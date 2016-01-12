#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 12;
int n;
ll b[N], acc[N], p;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d %lld",&n,&p);
        for(int i = 0; i < n; i++) scanf("%lld",b+i);
        acc[0] = 0;
        for(int i = 1; i <= n; i++) acc[i] = acc[i-1] + b[i-1];

        ll ans = 0;

        for(int i = 0; i < n; i++){
            int lo = i, hi = n-1;
            if(b[i] > p) continue;
            while (lo != hi){
                int mid = (lo + hi+1)/2;
                if(acc[mid+1] - acc[i] <= p) lo = mid;
                else hi = mid-1;
            }
            ans += lo-i+1;
        }
        printf("Case #%d: %lld\n",tc,ans);
    }
}

