#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;

struct query {
    int l,r,i,ans;
};

int n, Q, k = 1,rz;
const int N = 20015;
pii v[N];
query q[N];
int bit[N];
map<int,int> m;

int queryb (int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

void update (int idx, int val) {
    for(int i = idx; i < k; i += i&-i){
        bit[i] += val;
    }
}

bool comp (pii a, pii b){return a.ss < b.ss;}

bool comp2 (query a, query b){
    if(a.l/rz != b.l/rz) return a.l/rz < b.l/rz;
    return a.r < b.r;
}

bool comp3 (query a, query b){
    return a.i < b.i;
}

int main(){
    scanf("%d",&n);
    rz = sqrt(n);
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i].ff);
        v[i].ss = i;
    }
    sort(v,v+n);
    for(int i = 0; i < n; i++) {
        if(!m[v[i].ff]) m[v[i].ff] = k++;
        v[i].ff = m[v[i].ff];
    }
    sort(v,v+n,comp);
    scanf("%d",&Q);
    for(int i = 0; i < Q; i++){
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].i = i;
    }
    sort(q,q+Q,comp2);
    int cl = -1, cr = -1;
    int ans = 0;
    for(int i = 0; i < Q; i++){
        int l,r;
        l = q[i].l;
        r = q[i].r;
        while (cl > l){
            cl--;
            ans += queryb(v[cl].ff-1);
            update(v[cl].ff,1);
        }
        while (cl < l){
            ans -= queryb(v[cl].ff-1);
            update(v[cl].ff,-1);
            cl++;
        }
        while (cr > r){
            ans -= queryb(k-1) - queryb(v[cl].ff);
            update(v[cr].ff,-1);
            cr--;
        }
        while (cr < r){
            cr++;
            ans += queryb(k-1) - queryb(v[cr].ff);
            update(v[cr].ff,1);
        }
        q[i].ans = ans;
    }
    sort(q,q+Q,comp3);
    for(int i = 0; i < Q; i++) printf("%d\n",q[i].ans);
}

