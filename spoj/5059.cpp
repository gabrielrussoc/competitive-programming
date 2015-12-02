#include <bits/stdc++.h>
using namespace std;
typedef long long num;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        num ans = 0, x;
        for(int i = 0; i < n; i++){
            scanf("%lld",&x);
            while(x&1) x >>= 1;
            ans ^= x;
        }
        if(ans) puts("YES");
        else puts ("NO");
    }
}
