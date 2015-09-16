#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n, b;
    while(scanf("%lld %lld",&n,&b) != EOF){
    if(n <= (1ll << b+1)-1)
        printf("yes\n");
    else
        printf("no\n");
    }
}
