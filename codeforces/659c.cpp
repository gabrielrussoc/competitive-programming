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

int v[N],n,m,k;
int ans[N];

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++)
        scanf("%d",v+i);
    sort(v,v+n);
    
    int j = 1;
    while(j < v[0] && m >= j) {
        m -= j;
        ans[k++] = j;
        j++;
    }
    for(int i = 0; i < n-1; i++) {
        j = v[i]+1;
        while (j < v[i+1] && m >= j) {
            ans[k++] = j;
            m -= j;
            j++;
        }
    }
    j = v[n-1]+1;
    while(m >= j) {
        m -= j;
        ans[k++] = j;
        j++;
    }
    printf("%d\n",k);
    for(int i = 0; i < k; i++) printf("%d ",ans[i]);
    printf("\n");
    
}

