#include <cstdio>

using namespace std;

int main(){

    int k,a,b,v,ans = 0;
    scanf("%d %d %d %d",&k,&a,&b,&v);

    while(a > 0){
        if(b >= k-1){
            a -= v*k;
            b -= k-1;
        } 
        else{
            a -= v*(b+1);
            b = 0;
        }
        ans++;
    }
    printf("%d\n",ans);

}
