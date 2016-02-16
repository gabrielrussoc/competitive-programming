#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 100005;
const int modn = 1000000007;

int n, q, a, b;
int v[N];

struct no {
    int pv, pq, sv, sq, mq;
    no (){}
    no (int a, int b, int c,int d, int e) : pv(a), pq(b), sv(c), sq(d), mq(e) {}
} tree[4*N];

no join (no a, no b){
    no ret;
    
    // pre
    ret.pv = a.pv; ret.pq = a.pq;
    if(a.pv == b.pv) ret.pq = a.pq + b.pq;

    //suf
    ret.sv = b.sv; ret.sq = b.sq;
    if(b.sv == a.sv) ret.sq = a.sq + b.sq;

    //resp
    ret.mq = a.mq;
    ret.mq = max(ret.mq,b.mq);
    ret.mq = max(ret.mq,ret.sq);
    ret.mq = max(ret.mq,ret.pq);
    if(a.sv == b.pv) ret.mq = max(ret.mq, a.sq + b.pq);
    return ret;
}

void build(int k, int l, int r) {
    if(l == r) {
        tree[k] = no(v[l],1,v[r],1,1);
    }
    else {
        int m = (l+r)/2;
        build(2*k,l,m);
        build(2*k+1,m+1,r);
        tree[k] = join(tree[2*k],tree[2*k+1]);
    }
}

no query(int k, int l, int r, int fl, int fr){
    if(l >= fl && r <= fr) return tree[k];
    int m = (l+r)/2;
    if(fl > m || fr < l) return query(2*k+1,m+1,r,fl,fr);
    if(fr < m+1 || fl > r) return query(2*k,l,m,fl,fr); 
    return join(query(2*k,l,m,fl,fr), query(2*k+1,m+1,r,fl,fr));
}

int main() {
    while(scanf("%d",&n) && n){
        scanf("%d",&q);
        for(int i = 0; i < n; i++) scanf("%d",v+i);
        build(1,0,n-1);
        while(q--){
            scanf("%d %d",&a,&b);
            a--; b--;
            printf("%d\n",query(1,0,n-1,a,b).mq);      
        }
    }
}

