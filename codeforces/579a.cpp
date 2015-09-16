#include <cstdio>

int main(){
    int x;
    scanf("%d",&x);
    int k = 0;
    while(x){
        k += x%2;
        x /= 2;
    }
    printf("%d\n",k);
}
