#include <bits/stdc++.h>
using namespace std;
typedef long long ans;
//////////////0123456789
const int N = 200005;
int n, t, v[N], rz;
ll freq[1000006];
struct query{
    int l, r, i;
    ll ans;
} q[N];

ll ans;

bool comp (query a, query b){
    if(a.l/rz != b.l/rz) return a.l/rz < b.l/rz;
    return a.r < b.r;
}

bool comp2(query a, query b){
    return a.i < b.i;
}

void add(ll x){
    ans -= freq[x]*freq[x]*x;
    freq[x]++;
    ans += freq[x]*freq[x]*x;
}

void del(ll x){
    ans -= freq[x]*freq[x]*x;
    freq[x]--;
    ans += freq[x]*freq[x]*x;
}

int main(){
    memset(freq,0,sizeof freq);
    scanf("%d %d",&n,&t);
    rz = sqrt(n);
    for(int i = 0; i < n; i++)
        scanf("%d",v+i);
    for(int i = 0; i < t; i++){
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].i = i;
    }
    sort(q,q+t,comp);
    int cl, cr;
    ll ans = 0;
    int a,b;
    cl = cr = 0;
    add(v[0]);
    for(int i = 0; i < t; i++){
        a = query[i].l;
        b = query[i].r;
        while(cl < a){
            del(v[cl]);
            cl++;
        }
        while(cl > a){
            add(v[cl]);
            cl--;
        }
        while(cr <= b){
            add(v[cr]);
            cr++;
        }
        while(cr > b){
            del(v[cr]);
            cr--;
        }
        query[i].ans = ans;
    }
    sort(q,q+t,comp2);
    for(int i = 0; i < t; i++)
        printf("%d\n",query[i].ans);
}
