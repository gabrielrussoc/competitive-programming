#include <cstdio>
#include <cmath>

int main(){
    
    unsigned long long res, l,n;
    
    scanf("%llu %llu",&l,&n);
    res = (l-(n-1))*(l-(n-1)) + n-1;

    printf("%llu\n",res);

    return 0;
}
