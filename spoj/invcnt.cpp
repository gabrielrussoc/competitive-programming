#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int A = 10000007;
int t,n;
long long v[N], bit[A], maxi;

void update(int idx){
    for(int i = idx; i <= maxi; i += i&-i)
        bit[i]++;
}
long long query(int idx){
    long long sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main(){
    scanf("%d",&t);
    while(t--){
        memset(bit,0,sizeof bit);
        scanf("%d",&n);
        maxi = 0;
        for(int i = 0; i < n; i++){
            scanf("%lld",&v[i]);
            maxi = max(maxi,v[i]);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += i-query(v[i]);
            update(v[i]);
        }
        printf("%lld\n",ans);
    }
}
