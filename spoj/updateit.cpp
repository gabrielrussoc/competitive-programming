#include <bits/stdc++.h>

using namespace std;

const int N=10100;
long long bit[N];

int n,u;
int t,l,r,v;

void update(int idx, long long x){
    for(int i = idx; i <= n; i += i&-i)
        bit[i] += x;
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
        scanf("%d %d",&n,&u);
        for(int i = 0; i < u; i++){
            scanf("%d %d %d\n",&l,&r,&v);
            l++, r++;
            update(l,v);
            update(r+1,-v);
        }
        int q;
        scanf("%d",&q);
        for(int i = 0; i < q; i++){
            scanf("%d",&l);
            l++;
            printf("%lld\n",query(l));
        }
    }

}
