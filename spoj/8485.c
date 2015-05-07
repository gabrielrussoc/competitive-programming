#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 505

int main(){
    
    int v[MAX][MAX],i,j,m,n,q,k,l,u,mid,hi,lo;
    int baixo,alto,tam,x,y,flag,resp;
    
    while(scanf("%d %d",&n,&m) && n != 0){
        
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++)
                scanf("%d",&v[i][j]);
        }
        
        scanf("%d",&q);
        
        for(k = 0; k < q; k++){
            scanf("%d %d",&l,&u);
            resp = 0;
            
            for(i = 0; i < n; i++){
                lo = 0;
                hi = m - 1;
                while(hi > lo){
                    mid = (hi+lo)/2;
                    
                    if(v[i][mid] < l)
                        lo = mid+1;
                    else
                        hi = mid;
                }
                if(v[i][lo] >= l){
                    baixo = lo;
                    
                    lo = 0;
                    hi = m - 1;
                    
                    while(hi > lo){
                        mid = (hi+lo+1)/2;
                        
                        if(v[i][mid] > u)
                            hi = mid - 1;
                        else
                            lo = mid;
                    }
                    
                    if(v[i][lo] <= u){
                        alto = lo;
                        
                        if(alto-baixo+1 >= n-i)
                            tam = n-i;
                        else
                            tam = alto-baixo+1;
                        
                        for(x = resp+1; x <= tam; x++){
                            flag = 1;
                            
                            for(y = baixo; y <= x && flag; y++){
                                if(v[i][y] < l && v[i][y] > u)
                                    flag = 0;
                            }
                            if(flag)
                                resp = x;
                            
                        }
                    }
                }
            }
            printf("%d\n",resp);
        }
        printf("-\n");
        
    }
    
    
    return 0;
}