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

vector<int> tree[4*N];
int v[N], n,s,t,k,q;

void build(int k = 1, int l = 0, int r = n-1) {
    if(l == r) {
        tree[k].pb(v[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*k,l,mid);
    build(2*k+1,mid+1,r);
    merge(tree[2*k].begin(), tree[2*k].end(), tree[2*k+1].begin(), tree[2*k+1].end(), back_inserter(tree[k]));
}

int query(int fl, int fr, int num, int k=1, int l=0, int r=n-1) {
    if(l > fr || r < fl) return 0;
    if(l >= fl && r <= fr)
        return lower_bound(tree[k].begin(), tree[k].end(), num) - tree[k].begin();
    int mid = (l+r)/2;
    return query(fl,fr,num,2*k,l,mid) + query(fl,fr,num,2*k+1,mid+1,r);
}

int main() {
    scanf("%d %d",&n, &q);
    for(int i = 0; i < n; i++) scanf("%d",v+i);
    build();
    while(q--) {
        scanf("%d %d %d",&s,&t,&k);
        s--; t--;
        ll lo = -inf, hi = inf;
        while(lo < hi) {
            ll mid = (lo+hi+1)/2;
            if(query(s,t,mid) < k) lo = mid;
            else hi = mid-1;
        }
        printf("%d\n",lo);
    }
}


