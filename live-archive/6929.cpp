#include <cstdio>
#include <algorithm>

using namespace std;
int n, y;


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        
        int p = -1, j;
        for(int i = 2; i*i <= 2*n; i++){
            if((2*n)%i == 0){
                if((2*n/i -i +1)%2 == 0) {
                    p = (2*n/i -i +1)/2;
                    j = i;
                    break;
                }
            }
        }
        
        if(p != -1){
            printf("%d = %d",n,p);
            for(int k = p+1; k < p+j; k++)
                printf(" + %d",k);
            printf("\n");
        }
        else
            printf("IMPOSSIBLE\n");
    }

}
