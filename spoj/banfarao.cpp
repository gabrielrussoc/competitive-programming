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
const int N = 100003;
const int modn = 1000000007;

int n, acc[N], q;

struct no {
    int pi, pf, si, sf, mi, mf;
    no () {}
    no(int l):pi(l),pf(l),si(l),sf(l),mi(l),mf(l) {}
} tree[4*N];

int val(int a, int b){
    return acc[b+1] - acc[a];
}

no join(no a, no b){
    no ret;
    //pre
    if(val(a.pi, a.pf) > val(a.pi,a.sf) + val(b.pi,b.pf))
        ret.pi = a.pi, ret.pf = a.pf;
    else
        ret.pi = a.pi, ret.pf = b.pf;
    
    //suf
    if(val(b.si,b.sf) > val(b.pi,b.sf) + val(a.si,a.sf))
        ret.si = b.si, ret.sf = b.sf;
    else
        ret.si  = a.si, ret.sf = b.sf;

    //ans
    int ai,af;
    if(val(a.mi,a.mf) > val(b.mi,b.mf))
        ai = a.mi, af = a.mf;
    else if(val(a.mi,a.mf) == val(b.mi,b.mf)){
        if(a.mf-a.mi > b.mf - b.mi)
            ai = a.mi, af = a.mf;
        else
            ai = b.mi, af = b.mf;
    } else
        ai = b.mi, af = b.mf;

    if(val(ai,af) == val(a.si, a.sf) + val(b.pi, b.pf)){
        if(af-ai+1 < (a.sf - a.si+1) + (b.pf - b.pi+1))
            af = b.pf, ai = a.si;
    } else if (val(ai,af) < val(a.si, a.sf) + val(b.pi, b.pf))
        af = b.pf, ai = a.si;
    ret.mi = ai; ret.mf = af;
    return ret;
}

void build(int k, int l, int r){
    if(l == r)
        tree[k] = no(l);
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
    if (fl > m || fr < l) return query(2*k+1,m+1,r,fl,fr);
    if(fr < m+1 || fl > r) return query(2*k,l,m,fl,fr);
    return join(query(2*k,l,m,fl,fr),query(2*k+1,m+1,r,fl,fr));
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        acc[0] = 0;
        for(int i = 1; i <= n; i++){ 
            scanf("%d",acc+i);
            acc[i] += acc[i-1];
        }
        build(1,0,n-1);
        scanf("%d",&q);
        while(q--){
            int a,b;
            scanf("%d %d",&a,&b);
            no xab = query(1,0,n-1,a-1,b-1);
            printf("%d %d\n",val(xab.mi,xab.mf),xab.mf-xab.mi+1);

        }
    }
}

