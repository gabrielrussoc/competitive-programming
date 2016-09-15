#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 1e5+7;

int v[N];

int main() {
    int n;
    scanf("%d",&n);
    ll ans = 0;
    for(int i = 0; i < n; i++) scanf("%d",v+i);
    int i = 0, j = 0;
    while(i < n) {
        while(!v[i] && i < n) i++;
        j = i;
        while(v[j] && j < n) j++;
        ll k = j-i;
        ans += (k*(k+1ll))/2ll;
        i = j+1;
    }
    printf("%lld\n",ans);


}

