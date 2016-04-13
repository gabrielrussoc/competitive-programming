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
const int N = 1000006;
const int modn = 1000000007;

int in[2*N], v[N], q[N], bit[N], t, n, d, k, g;

void add(int idx, int val) {
    for(int i = idx; i < g; i += i&-i)
        bit[i] += val;
}

int query (int idx) {
    int sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&d);
        v[0] = k = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d",in+i);
            if(in[i] != v[k]) v[++k] = in[i]; 
        }
        v[++k] = 0;

        for(int i = n; i < n+d; i++) {
            scanf("%d",in+i);
            q[i-n] = in[i];   
        }
        in[n+d] = 0;
        
        sort(in, in+n+d+1);
        g = unique(in, in+n+d+1) - in;
        for (int i = 0; i < g; i++) bit[i] = 0;
        for(int i = 1; i < k; i++)
            v[i] = lower_bound(in,in+g,v[i]) - in;
        for(int i = 0; i < d; i++)
            q[i] = lower_bound(in,in+g,q[i]) - in;

        for(int i = 1; i < k; i++){
            if(v[i] < v[i-1] && v[i] < v[i+1])
                add(v[i],1);
            else if (v[i] > v[i-1] && v[i] > v[i+1])
                add(v[i],-1);
        }
        for(int i = 0; i < d; i++) printf("%d%c", query(q[i])+1,i == d-1 ? '\n' : ' ');
    }
}

