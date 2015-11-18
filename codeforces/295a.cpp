#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,k;
const int N = 100005;

struct opofessocetameouvino {
    int l, r;
    ll d;
} op[N];
ll a[N], bitop[N], bitq[N];

ll queryop (int idx){
    ll sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum += bitop[i];
    return sum;
}
void updateop(int idx, ll val){
    for(int i = idx; i < N; i += i&-i)
        bitop[i] += val;
}
ll queryq (int idx){
    ll sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum += bitq[i];
    return sum;
}
void updateq(int idx, ll val){
    for(int i = idx; i < N; i += i&-i)
        bitq[i] += val;
}


int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0; i < n; i++) scanf("%I64d",a+i);
    for(int i = 0; i < m; i++)
        scanf("%d %d %I64d",&op[i].l,&op[i].r,&op[i].d);
    int l, r;
    for(int i = 0; i < k; i++){
        scanf("%d %d",&l, &r);
        updateop(r+1,-1);
        updateop(l,1);
    }
    for(int i = 0; i < m; i++){
        ll val = queryop(i+1);
        updateq(op[i].l,val*op[i].d);
        updateq(op[i].r+1,-val*op[i].d);
    }
    for(int i = 0; i < n; i++){
        printf("%I64d ",a[i] + queryq(i+1));
    }
    printf("\n");

}
