#include <cstdio>
typedef long long num;

using namespace std;

const int MODN = 1000000007;

num fexp(num x, num n){
    if(n == 1) return x;
    if(n == 0) return 1;
    if(n%2 == 0) return fexp((x*x)%MODN,n/2);
    return (x*fexp((x*x)%MODN,n/2)%MODN);
}


int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        num aux,ans;
        if(n % 2 == 0) { 
            aux = fexp(2,n/2);
            ans = (2*(aux-1) + aux)%MODN;
        } else {
            ans = (fexp(2,n/2 + 2)-2)%MODN;
        }
        printf("%lld\n",ans);

    }
}