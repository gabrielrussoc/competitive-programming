#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;
const int N = 30004, Q = 200007;
int bit[N];
int n,q, ans[Q];
pii v[N];
struct colombo {
    int i,j,k,o;
    bool operator < (const colombo& x) const {
        return o < x.o;
    }
} query[Q];

bool compk(colombo a, colombo b){ return a.k > b.k; }

void update(int idx, int val){
    for(int i = idx; i <= n; i += i&-i)
        bit[i] += val;
}

int qry(int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i <= n; i++) bit[i] = 0;
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i].ff);
        v[i].ss = i+1;
    }
    sort(v,v+n);
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        scanf("%d %d %d",&query[i].i,&query[i].j,&query[i].k);
        query[i].o = i;        
    }
    sort(query,query+q,compk);
    int j = n-1;
    for(int i = 0; i < q; i++){
        while(j >= 0 && v[j].ff > query[i].k) update(v[j--].ss,1);
        ans[query[i].o] = qry(query[i].j) - qry(query[i].i -1);
    }
    for(int i = 0; i < q; i++)
        printf("%d\n",ans[i]);   
}
