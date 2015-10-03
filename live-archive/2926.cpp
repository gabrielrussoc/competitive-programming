#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;

int t,n,m,k, bit[1004];
pii v[1000006];

long long query(int idx){
    long long sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

void update(int idx) {
    for(int i = idx; i <= m; i += i&-i)
        bit[i]++;
}

int main(){
    scanf("%d",&t);
    int tc = 1;
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        for(int i = 0; i <= m; i++) bit[i] = 0;
        for(int i = 0; i < k; i++)
            scanf("%d %d",&v[i].ff,&v[i].ss);
        sort(v,v+k);
        long long ans = 0;
        for(int i = k-1; i >= 0; i--){
            ans += query(v[i].ss-1);
            update(v[i].ss);
        }
        printf("Test case %d: %lld\n",tc++,ans);
    }
}
