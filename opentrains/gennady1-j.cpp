#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6;

ll v[N];
int k, j;

void getdiv(ll x){
}

int main(){
    freopen("job.in","r",stdin);
    freopen("job.out","w",stdout);
    ll n;
    scanf("%lld",&n);
    for(ll i = 1; i*i <= n; i++)
        if(n%i == 0) v[k++] = i, v[k++] = n/i;
    j = k;
    for(int i = 0; i < k; i++){
        ll x = n-v[i];
        getdiv(x);
    }
    sort(v,v+j);
    j = unique(v,v+j) - v;
    printf("%d\n",j);
}
