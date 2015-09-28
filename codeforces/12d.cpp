#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

int n, bit[N];
map<int,int> m;

struct lady {
    int b,i,r;
} v[N];

bool compx(lady a, lady b){
    if(a.i > b.i) return true;
    return false;
}

bool compz(lady a, lady b){
    if(a.b == b.b) return a.i > b.i;
    return a.b > b.b;
}

void update(int idx, int val){
    for(int i = idx; i <= n; i += i&-i)
        bit[i] = max(bit[i],val);
}

int query(int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum = max(sum,bit[i]);
    return sum;
}

int main(){
    memset(bit,0,sizeof bit);
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++)
        scanf(" %d",&v[i].b);
    for(int i = 0; i < n; i++)
        scanf(" %d",&v[i].i);
    for(int i = 0; i < n; i++)
        scanf(" %d",&v[i].r);

    sort(v,v+n,compx);
    int k = 1;
    for(int i = 0; i < n; i++){ 
        if(m[v[i].i] == 0) m[v[i].i] = k++;
        v[i].i = m[v[i].i];
    }

    sort(v,v+n,compz);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(query(v[i].i-1) > v[i].r) ans++;
        update(v[i].i,v[i].r);
    }
    printf("%d\n",ans);
}
