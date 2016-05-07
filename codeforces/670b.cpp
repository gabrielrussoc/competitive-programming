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

int v[N];
int n, k;


int main() {
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++) scanf("%d",v+i);
    ll i;
    for(i = 1; i <= n; i++) {
        if((i*(i+1))/2 >= k)
            break;
    }
    ll at = ((i-1)*i)/2;
    at++;
    int j = 0;
    while(at < k){
       at++, j++;
    }
    printf("%d\n",v[j]);
}

