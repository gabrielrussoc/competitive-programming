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
const int N = 50004;
const int modn = 1000000007;

int a[N], b[N], c[N], p[N], v[N], t, n;
int bit[N];

bool comp (int i, int j){ return b[i] < b[j]; }

void add (int idx) {
    for(int i = idx+2; i < N; i += i&-i)
        bit[i]++;
}

int query(int idx) {
    int sum = 0;
    for(int i = idx+2; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d %d %d",a+i,b+i,c+i);
            p[i] = i;
        }
        for(int i = 0; i < N; i++) {
            v[i] = i-1;
            bit[i] = 0;
        }
        sort(p,p+n,comp);
        for(int i = 0; i < n; i++){
            int q = c[p[i]] - query(b[p[i]]) + query(a[p[i]]-1);
            for(;q > 0; q--){
                int k = v[b[p[i]]+1];
                add(k);
                v[b[p[i]]+1] = v[k];
            }
        }
        printf("%d\n",query(50000));
    }
}

