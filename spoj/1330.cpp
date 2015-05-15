#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>

int main(){

    int x1,x2,y1,y2,t=1,n,a,b,cont;
    while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2) && x1 || x2 || y1 || y2){
        cont = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d %d",&a,&b);
            if((a >= x1 && a <= x2) && (b <= y1 && b >= y2))
                cont++;
        }
        printf("Teste %d\n",t++);
        printf("%d\n\n",cont);
    }

    return 0;
}
