#include <stdio.h>
int main(){
    
    int n,at,max,t,p,c,f,l,i,mf;
    
    t = 1;
    while(scanf("%d",&n) && n != 0){
        at = max = 0;
        f = 1;
        for(i = 0; i < n; i++){
            scanf("%d %d",&p,&c);
            at += p - c;
            if(at < 0){
                at = 0;
                f = i + 2;
            }
                
    
            if(at >=  max){
                mf = f;
                max = at;
                l = i + 1;
            }
        }

        printf("Teste %d\n",t);
        if(!max)
            printf("nenhum\n");
        else
            printf("%d %d\n",mf,l);
        t++;
    }

    return 0;
}
