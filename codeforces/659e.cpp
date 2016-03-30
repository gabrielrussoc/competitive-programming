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
const int M = 100005;
const int modn = 1000000007;

int n, m, u, v, es;

int uf[N], wf[N], can[N];

int find (int i) {
    if (i == uf[i]) return i;
    return uf[i] = find(uf[i]);
}

int join (int i, int j) {
    i = find(i); j = find(j);
    if(i == j) return 0;
    if(wf[i] > wf[j]) swap(i,j);
    can[j] |= can[i];
    wf[j] += wf[i];
    uf[i] = j;
    return 1;
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++) uf[i] = i, wf[i] = 1;
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&u, &v);
        u--; v--;
        if(!join(u,v)) 
            can[find(u)] = 1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) if(i == uf[i] && !can[i]) ans++; 
    printf("%d\n",ans);

}

