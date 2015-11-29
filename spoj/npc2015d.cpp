#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modn = 1e9 + 7;

ll fexp(ll n, ll k) {
    ll r = 1;
    while(k > 0){
        if(k&1) r = (n*r)%modn;
        n = (n*n)%modn;
        k >>= 1;
    }
    return r%modn;
}

int main(){
    ll n;
    scanf("%lld",&n);
    ll k = n/3;
    ll r = fexp(3,k-1);
    if(n < 5) r = n;
    else if(n%3 == 0) r *= 3;
    else if(n%3 == 1) r*= 4;
    else r *= 6;
    printf("%lld\n",r%modn);
}
