#include <cstdio>

int main(){
    int maxi = 0, ind, num;
    for(int i = 0; i < 100; i++){
        scanf("%d",&num);
        if(num > maxi) maxi = num, ind = i+1;
    }
    printf("%d\n%d\n",maxi,ind);
}
